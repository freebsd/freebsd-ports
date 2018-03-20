# $FreeBSD$

PORTNAME=	smart
DISTVERSION=	0.0.8
CATEGORIES=	sysutils

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Output disk SMART values

LICENSE=	ISCL

IGNORE_FreeBSD_10=	Requires FreeBSD 11 or later

USE_GITHUB=	yes
GH_ACCOUNT=	ctuffli

PLIST_FILES=	sbin/atasmart sbin/nvmesmart sbin/scsismart sbin/smart

post-patch:
	@${REINPLACE_CMD} -e "s|./${PORTNAME}|${PREFIX}/sbin/${PORTNAME}|" \
		${WRKSRC}/[ans]*${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/[ans]*${PORTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
