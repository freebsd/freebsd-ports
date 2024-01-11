PORTNAME=	smart
DISTVERSION=	0.4.1
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Output disk SMART values
WWW=		https://github.com/ctuffli/smart

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	ctuffli

PLIST_FILES=	share/man/man8/smart.8.gz \
		sbin/atasmart \
		sbin/nvmesmart \
		sbin/scsismart \
		sbin/smart

post-patch:
	@${REINPLACE_CMD} -e "s|./${PORTNAME}|${PREFIX}/sbin/${PORTNAME}|" \
		${WRKSRC}/[ans]*${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/[ans]*${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/smart.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
