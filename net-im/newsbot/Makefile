# ex:ts=8
# Ports collection makefile for:	newsbot
# Date created:			Mar 12, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	newsbot
PORTVERSION=	0.4.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.jabberstudio.org/files/${PORTNAME}/
DISTNAME=	${PORTNAME}-0.45

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gathers news from RDF/RSS and send them to your IM client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/jabber/jabber.py:${PORTSDIR}/net/py-jabber

USE_PYTHON=	2.2+
NO_BUILD=	yes

PLIST_FILES=	bin/newsbot

do-install:
	@${SED} "s,%%DATADIR%%,${DATADIR}," \
		< ${FILESDIR}/newsbot > ${PREFIX}/bin/newsbot
	@${CHMOD} +x ${PREFIX}/bin/newsbot
	@${MKDIR} ${DATADIR}
	@(cd ${WRKSRC} && ${INSTALL_DATA} *.py *.cfg README bothelp ${DATADIR})
	@${FIND} ${DATADIR} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${DATADIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.mk>
