# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	please
PORTVERSION=	2.0
CATEGORIES=	security

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Execute a command as root

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	rst2man:${PORTSDIR}/textproc/py-docutils

USE_GITHUB=	yes
GH_ACCOUNT=	MagikBSD
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	1d65ba2

INSTALL_TARGET=	install install-pam
PLIST_FILES=	"@(,,6555) bin/please" etc/pam.d/please.sample man/man1/please.1.gz

post-patch:
	@${REINPLACE_CMD} -e "s,-o 0 -g 0,,g ; s,-m 6555,-m 0555,g" \
		-e "s,\(\$${PAMDIR}/\$${BIN}\),\\1.sample," \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
