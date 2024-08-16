PORTNAME=	coi
DISTVERSION=	2.3.9
PORTREVISION=	4
CATEGORIES=	mail
PKGNAMEPREFIX=	dovecot-

MAINTAINER=	andrej@ebert.su
COMMENT=	Dovecot COI (Chat-over-IMAP) plugin

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	dovecot>=2.3.8:mail/dovecot
RUN_DEPENDS=	dovecot>=2.3.8:mail/dovecot

USES=		autoreconf compiler:c++11-lang libtool pkgconfig

DOVECOTVERSION=	2.3

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--exec-prefix=${PREFIX} \
		--without-dovecot-install-dirs \
		--with-dovecot="${LOCALBASE}/lib/dovecot"

MAKE_ARGS=	LD_RUN_PATH="${PREFIX}/lib/dovecot" \

INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	UNFINISHED
OPTIONS_SUB=	yes

UNFINISHED_DESC=	Build unfinished modules, currently doveadm-coi and submission-coi
UNFINISHED_CONFIGURE_ENABLE=	unfinished

USE_GITHUB=yes
GH_ACCOUNT=	dovecot

.include <bsd.port.mk>
