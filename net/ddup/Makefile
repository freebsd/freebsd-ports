# New ports collection makefile for:	ddup
# Date created:		30 September 1999
# Whom:			cjm2
#
# $FreeBSD$
#

PORTNAME=	ddup
PORTVERSION=	3.0.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITES_LOCAL}
DISTNAME=	${PORTNAME}-${PORTVERSION}-unix

MAINTAINER=	ports@FreeBSD.Org

USE_REINPLACE=	yes

MAN1=		ddup.1
MANCOMPRESSED=	maybe

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

# Uncomment this if you want to enable debugging.
#DEBUG=		-g

MAKE_ARGS=	DEBUG="${DEBUG}"

post-extract:
	cd ${WRKSRC}; ${GUNZIP_CMD} ddup.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,!!PREFIX!!,${PREFIX},' ${WRKSRC}/ddupcron.sh
	@${REINPLACE_CMD} -e 's,/etc\b,${PREFIX}$$&,' ${WRKSRC}/ddup.1

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/
	${ECHO_CMD} "#define file_name \"${PREFIX}/etc/ddup.conf\"" > ${WRKSRC}/options.h

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ddupcron.sh ${PREFIX}/sbin/
.if !defined(NOPORTSDOC)
	${MKDIR} ${PREFIX}/share/doc/ddup
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ddup/
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
