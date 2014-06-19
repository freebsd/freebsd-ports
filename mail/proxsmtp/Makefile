# Created by: Dario Freni <saturnero@gufi.org>
# $FreeBSD$

PORTNAME=	proxsmtp
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	mail security
MASTER_SITES=	http://thewalter.net/stef/software/proxsmtp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible SMTP filter which can act also as transparent proxy

LICENSE=	BSD3CLAUSE

USES=		gmake
GNU_CONFIGURE=	yes

USE_RC_SUBR=	proxsmtpd
SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		'/^acx_pthread_flags/s|=.*|="${PTHREAD_LIBS}"|' \
		${WRKSRC}/configure

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} proxsmtpd.conf \
		${STAGEDIR}${PREFIX}/etc/proxsmtpd.conf.sample)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
