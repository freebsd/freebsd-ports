PORTNAME=	openarc
DISTVERSION=	1-0-0-Beta3.20201016
PORTREVISION=	2
CATEGORIES=	mail

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to validate use of certain identifiers in messages
WWW=		https://github.com/trusteddomainproject/OpenARC

LICENSE=	BSD2CLAUSE SENDMAIL
LICENSE_COMB=	multi
LICENSE_GROUPS_SENDMAIL=	FSF OSI
LICENSE_NAME_SENDMAIL=	Sendmail Open Source License
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/LICENSE
LICENSE_FILE_SENDMAIL=	${WRKSRC}/LICENSE.Sendmail
LICENSE_PERMS_SENDMAIL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	autoconf-archive>0:devel/autoconf-archive
LIB_DEPENDS=	libjansson.so:devel/jansson

USES=		autoreconf gmake libtool localbase pkgconfig ssl
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trusteddomainproject
GH_PROJECT=	OpenARC
GH_TAGNAME=	eb430db

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE}

USE_RC_SUBR=	${PORTNAME}

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

.include <bsd.port.mk>
