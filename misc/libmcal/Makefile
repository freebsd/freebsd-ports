# New ports collection makefile for:	libmcal
# Date created:		Sat Oct 13 08:45:04 GMT 2001
# Whom:			thierry@thomas.as
#
# $FreeBSD$
#

PORTNAME=	libmcal
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mcaldrivers-0.9.tar.gz

MAINTAINER=	thierry@pompo.net
COMMENT=	Modular Calendar Access Library

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl

HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-mstore --with-icap \
		--prefix=${PREFIX} --exec-prefix=${PREFIX}
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
WRKSRCDRV=	${WRKDIR}/mcal-drivers

DOCS=		CHANGELOG FAQ-MCAL FEATURE-IMPLEMENTATION FUNCTION-REF.html \
		HOW-TO-MCAL LICENSE README mstore/README.mstore

post-extract:
	${CP} -pR ${WRKSRCDRV}/mstore ${WRKSRC}
	${CP} -pR ${WRKSRCDRV}/icap ${WRKSRC}
	${MV} ${WRKSRC}/mstore/Makefile ${WRKSRC}/mstore/Makefile.dist
	${MV} ${WRKSRC}/mstore/Makefile.FreeBSD ${WRKSRC}/mstore/Makefile
	${MV} ${WRKSRC}/icap/Makefile ${WRKSRC}/icap/Makefile.dist
	${MV} ${WRKSRC}/icap/Makefile.FreeBSD ${WRKSRC}/icap/Makefile
	${MV} ${WRKSRC}/configure ${WRKSRC}/configure.dist
	${MV} ${WRKSRC}/configure.FreeBSD ${WRKSRC}/configure
	${CHMOD} u+x ${WRKSRC}/configure
	${MV} ${WRKSRC}/mstore/README ${WRKSRC}/mstore/README.mstore

post-patch:
	${REINPLACE_CMD} -e "s:/etc/mpasswd:${PREFIX}/etc/mpasswd:" ${WRKSRC}/mstore/mstore.c

pre-configure:
	@${ECHO_MSG} "===>  Building the driver mstore"
	cd ${WRKSRC}/mstore ; \
		${MAKE}
	@${ECHO_MSG} "===>  Building the driver icap"
	cd ${WRKSRC}/icap ; \
		${MAKE}

post-install:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s:/etc/mpasswd:${LOCALBASE}/etc/mpasswd:" \
		${WRKSRC}/FAQ-MCAL
	${REINPLACE_CMD} -e "s:/etc/mpasswd:${LOCALBASE}/etc/mpasswd:" \
		${WRKSRC}/mstore/README.mstore
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===>  Documentation installed in ${DOCSDIR}."
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s:%%LOCALBASE%%:${LOCALBASE}:g"
	@${ECHO}

.include <bsd.port.mk>
