# $FreeBSD$

PORTNAME=	proxy65
PORTVERSION=	1.2.0.20150210
PORTREVISION=	1
CATEGORIES=	net-im

MAINTAINER=	mm@FreeBSD.org
COMMENT=	XEP-0065 SOCKS5 Bytestreams external component for Jabber

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/OpenSSL/__init__.py:security/py-openssl@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}twisted>=0:devel/py-twisted@${FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska
GH_TAGNAME=	4e76bf2

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE= SERVER
OPTIONS_SINGLE_SERVER= NOJABBER JABBER JABBERD EJABBERD
OPTIONS_DEFAULT=	NOJABBER
NOJABBER_DESC=    Do not depend on a jabber server
JABBER_DESC=    Use with jabberd14 (net-im/jabber)
JABBERD_DESC=   Use with jabberd 2.x (net-im/jabberd)
EJABBERD_DESC=  Use with ejabberd (net-im/ejabberd)

USE_PYTHON=	distutils autoplist
USES=		python:2
USE_RC_SUBR=	proxy65

PORTDOCS=	README

PROXY65_USER=	proxy65
PROXY65_GROUP=	proxy65
USERS=		${PROXY65_USER}
GROUPS=		${PROXY65_GROUP}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNOJABBER}
# No jabber depends
.elif ${PORT_OPTIONS:MJABBER}
JABBER_REQUIRE?=        jabber
RUN_DEPENDS+=           jabberd14:net-im/jabber
.elif ${PORT_OPTIONS:MJABBERD}
JABBER_REQUIRE?=        jabberd
RUN_DEPENDS+=           jabberd:net-im/jabberd
.elif ${PORT_OPTIONS:MEJABBERD}
JABBER_REQUIRE?=        ejabberd
RUN_DEPENDS+=           ejabberdctl:net-im/ejabberd
.endif

SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}" \
		JABBER_REQUIRE="${JABBER_REQUIRE}" \
		PROXY65_USER=${PROXY65_USER} \
		PROXY65_GROUP=${PROXY65_GROUP}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} -m 0640 ${FILESDIR}/proxy65.ini.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
