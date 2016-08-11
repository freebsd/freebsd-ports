# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	please
PORTVERSION=	2.5
CATEGORIES=	security

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Execute a command as root

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	MagikBSD

PLIST_FILES=	"@(,,4555) bin/please" "@sample etc/pam.d/please.sample" \
		man/man1/please.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s,-m 4555,-m 0555,g" ${WRKSRC}/Makefile

post-install:
	${CP} ${WRKSRC}/pam.d/please.FreeBSD \
		${STAGEDIR}${PREFIX}/etc/pam.d/please.sample

.include <bsd.port.mk>
