# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmpppy-irc
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	net-im python irc
MASTER_SITES=	SF/xmpppy/PyIRCt/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	irc-transport-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xmpp to irc transport

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/xmpp/__init__.py:net-im/py-xmpppy \
		${PYTHON_PKGNAMEPREFIX}irc>0:irc/py-irc

USES=		python
NO_BUILD=	yes
FILES=		irc.py jep0106.py jep0133.py test_jep0106.py
PFILES=		${FILES:S.^.%%PYTHON_SITELIBDIR%%/xmpp/irc/.}
PLIST_FILES=	${PFILES} ${PFILES:S.$.c.} ${PFILES:S.$.o.} etc/${PORTNAME:S.-..}.conf.sample
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} FEXEC=${PYTHON_SITELIBDIR}/xmpp/irc/irc.py
USE_RC_SUBR=	xmpppyirc
PORTDOCS=	ChangeLog IRC-Transport-Howtouse.html README.txt
DDIR=		${PYTHON_SITELIBDIR}/xmpp/irc

PORTSCOUT=	limit:^0\.4[1-4]

OPTIONS_DEFINE=	DOCS

post-patch:
	@${GREP} -lr '/usr/bin/python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e "s,/usr/bin/python,${PYTHON_CMD}," \
			-e "s!/etc/jabber/jabber-irc.conf!${PREFIX}/etc/${PORTNAME:S.-..}.conf!"

do-install:
	@${INSTALL} -d ${STAGEDIR}${DDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/irc.py ${STAGEDIR}${DDIR}/
	${INSTALL_DATA} ${FILES:M*jep*:S.^.${WRKSRC}/.} ${STAGEDIR}${DDIR}/
	${INSTALL_DATA} ${WRKSRC}/transport.ini ${STAGEDIR}${PREFIX}/etc/${PORTNAME:S.-..}.conf.sample
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DDIR} ${STAGEDIR}${DDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -d ${DDIR} ${STAGEDIR}${DDIR}
	@${CHMOD} -R a-w ${STAGEDIR}${DDIR}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	${INSTALL} ${PORTDOCS:S.^.${WRKSRC}/.} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
