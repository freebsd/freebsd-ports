# ex:ts=8
# Ports collection makefile for:	anubis
# Date created:			Jul 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	anubis
PORTVERSION=	3.4.0
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gpgme:${PORTSDIR}/security/gpgme \
		pcre:${PORTSDIR}/devel/pcre \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

MAN1=	anubis.1

post-patch:
	@${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" ${WRKSRC}/src/headers.h
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/anubis.sh > \
		${WRKSRC}/anubis.sh

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/anubis.sh ${PREFIX}/etc/rc.d
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
