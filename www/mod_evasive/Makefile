# Created by: Xavier Beaudouin <kiwi@oav.net>
# $FreeBSD$

PORTNAME=	mod_evasive
PORTVERSION=	1.10.1
PORTREVISION=	1
CATEGORIES=	www security
MASTER_SITES=	http://www.zdziarski.com/blog/wp-content/uploads/2010/02/
DISTNAME=	mod_evasive_${PORTVERSION}
DIST_SUBDIR=	apache2

MAINTAINER=	kiwi@oav.net
COMMENT=	Apache module to try to protect the HTTP Server from DoS/DDoS attacks

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		apache:2.2+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MODULENAME=	${PORTNAME}20

PORTDOCS=	README test.pl

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/mail|/usr/bin/mail|g" \
		${WRKSRC}/mod_evasive.c ${WRKSRC}/mod_evasive20.c \
		${WRKSRC}/mod_evasiveNSAPI.c
.if ${APACHE_VERSION:M2.4}
	@${REINPLACE_CMD} -e 's/remote_ip/client_ip/g' ${WRKSRC}/mod_evasive20.c
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
