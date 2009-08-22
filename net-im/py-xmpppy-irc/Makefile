# Ports collection makefile for:	py-irc-transport
# Date created:				21 April 2006
# Whom:					Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmpppy-irc
PORTVERSION=	0.3
CATEGORIES=	net-im python irc
MASTER_SITES=	SF/xmpppy/PyIRCt/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	irc-transport-${PORTVERSION}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An xmpp to irc transport

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xmpp/__init__.py:${PORTSDIR}/net-im/py-xmpppy \
		${PYTHON_SITELIBDIR}/irclib.py:${PORTSDIR}/irc/py-irclib

USE_PYTHON=	2.3+
NO_BUILD=	yes
FILES=		irc.py jep0106.py jep0133.py test_jep0106.py
PFILES=		${FILES:S.^.%%PYTHON_SITELIBDIR%%/xmpp/irc/.}
PLIST_FILES=	${PFILES} ${PFILES:S.$.c.} ${PFILES:S.$.o.} etc/${PORTNAME:S.-..}.conf.sample
PLIST_DIRS=	%%PYTHON_SITELIBDIR%%/xmpp/irc
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} FEXEC=${PYTHON_SITELIBDIR}/xmpp/irc/irc.py
USE_RC_SUBR=	xmpppyirc
PORTDOCS=	ChangeLog IRC-Transport-Howtouse.html README.txt
DDIR=		${PYTHON_SITELIBDIR}/xmpp/irc

PORTSCOUT=	limit:^0\.4[1-4]

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD}," \
			-e "s!/etc/jabber/jabber-irc.conf!${PREFIX}/etc/${PORTNAME:S.-..}.conf!"

do-install:
	@${INSTALL} -d ${DDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/irc.py ${DDIR}/
	@${INSTALL_DATA} ${FILES:M*jep*:S.^.${WRKSRC}/.} ${DDIR}/
	@${INSTALL_DATA} ${WRKSRC}/transport.ini ${PREFIX}/etc/${PORTNAME:S.-..}.conf.sample
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${DDIR}
	@${CHMOD} -R a-w ${DDIR}
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}
	@${INSTALL} ${PORTDOCS:S.^.${WRKSRC}/.} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
