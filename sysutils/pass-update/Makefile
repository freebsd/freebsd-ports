PORTNAME=	pass-update
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1
CATEGORIES=	sysutils

MAINTAINER=	vendion@gmail.com
COMMENT=	Pass extension that provides an easy flow for updating passwords

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash \
		pass:sysutils/password-store

USES=		gmake shebangfix
USE_GITHUB=	YES
GH_ACCOUNT=	roddhjav
SHEBANG_FILES=	tests/*.sh update.bash

NO_ARCH=	yes
NO_BUILD=	yes
MAKE_ENV=	BASHCOMPDIR=${PREFIX}/share/bash-completions/completions \
		DESTDIR=${STAGEDIR} \
		LIBDIR=${PREFIX}/libexec \
		MANDIR=${MANPREFIX}/man

PLIST_FILES=	libexec/password-store/extensions/update.bash \
		man/man1/pass-update.1.gz \
		share/bash-completions/completions/pass-update \
		share/zsh/site-functions/_pass-update

.include <bsd.port.mk>
