# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yahoo
PORTVERSION=	0.3.20070314
PORTREVISION=	1
CATEGORIES=	net-im python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=lofi
PKGNAMEPREFIX=	xmpppy-
DISTNAME=	yahoo-transport-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yahoo! transport for Jabber

OPTIONS_DEFINE=	EJABBERD
EJABBERD_DESC=	transport with ejabberd

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xmpp/__init__.py:${PORTSDIR}/net-im/py-xmpppy \
		${PYTHON_SITELIBDIR}/DNS/__init__.py:${PORTSDIR}/dns/py-dns

USES=		python
NO_BUILD=	yes
FILES=		adhoc.py config.py jep0133.py roomlist.py xmlconfig.py \
		yahoo_helpers.py avatar.py htmlutils.py migratespool.py toolbox.py \
		yahoo.py ylib.py
FILES_CURPHOO=	YahooMD5.py __init__.py cpformat.py md5crypt.py pysha.py yahoo_fn.py
PFILES=		${FILES:S.^.%%PYTHON_SITELIBDIR%%/xmpp/yahoo/.} \
		${FILES_CURPHOO:S.^.%%PYTHON_SITELIBDIR%%/xmpp/yahoo/curphoo/.}
PLIST_FILES=	${PFILES} ${PFILES:S.$.c.} ${PFILES:S.$.o.} etc/${UNIQUENAME:S.-._.}.conf.sample
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/xmpp/yahoo/curphoo %%PYTHON_SITELIBDIR%%/xmpp/yahoo
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD} BINDIR=${PYTHON_SITELIBDIR}/xmpp/yahoo \
		JABBER_USER=${JABBER_USER}
USE_RC_SUBR=	${UNIQUENAME:S/-/_/}
DDIR=		${PYTHON_SITELIBDIR}/xmpp/yahoo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEJABBERD}
JABBER_USER?=	ejabberd
SUB_LIST+=	JABBER_REQUIRE=ejabberd
.else
JABBER_USER?=	jabber
SUB_LIST+=	JABBER_REQUIRE=jabberd
.endif

post-patch:
	@${GREP} -lr '/usr/bin/env python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s|/usr/bin/env python|${PYTHON_CMD}|"
	@${REINPLACE_CMD} -e "s|/etc/pyyimt.conf.xml|${PREFIX}/etc/${UNIQUENAME:S.-._.}.conf|" \
		-e 's|pid = ""|pid = "/var/jabberd/pid/PyYIMt.pid"|g' \
		-e 's|spoolFile = "user.dbm"|spoolFile = "/var/spool/jabberd/yahoouser.dbm"|g' \
		${WRKSRC}/config.py
	@${REINPLACE_CMD} -e '/spoolFile/s|yahoouser.dbm|/var/spool/jabberd/yahoouser.dbm|' \
			-e 's|<debugFile.*|<!-- <debugFile>yahooerror.log</debugFile> -->|' \
		-e 's|PyYIMt.pid|/var/jabberd/pid/PyYIMt.pid|' \
		${WRKSRC}/config_example.xml

do-install:
	@${INSTALL} -d ${STAGEDIR}${DDIR}
	${INSTALL_DATA} ${FILES:S.^.${WRKSRC}/.} ${STAGEDIR}${DDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/yahoo.py ${STAGEDIR}${DDIR}/
	@${MKDIR} ${STAGEDIR}${DDIR}/curphoo
	${INSTALL_DATA} ${FILES_CURPHOO:S.^.${WRKSRC}/curphoo/.} ${STAGEDIR}${DDIR}/curphoo/
	${INSTALL_DATA} ${WRKSRC}/config_example.xml ${STAGEDIR}${PREFIX}/etc/${UNIQUENAME:S.-._.}.conf.sample
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DDIR} ${STAGEDIR}${DDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${DDIR} ${STAGEDIR}${DDIR}
	@${CHMOD} -R a-w ${STAGEDIR}${DDIR}

.include <bsd.port.mk>
