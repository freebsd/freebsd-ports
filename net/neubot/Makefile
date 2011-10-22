# New ports collection makefile for:	neubot
# Date created:		Wed 18 oct 2011
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	neubot
PORTVERSION=	0.4.2
CATEGORIES=	net
MASTER_SITES=	http://releases.neubot.org/_packages/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Measures neutrality of your network connection in the background

LICENSE=	GPLv3

USE_PYTHON=	2.5-2.9

NO_BUILD=	yes

USERS=		_neubot
GROUPS=		_neubot

USE_RC_SUBR=	neubotd
INSTALLS_ICONS=	yes

MAN1=		neubot.1
PORTDOCS=	AUTHORS BUGS ChangeLog PRIVACY README TODO

SUB_FILES=	pkg_message
SUB_LIST+=	PYTHON_CMD=${PYTHON_CMD}
PKGMESSAGE=	${WRKDIR}/pkg_message

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/${MAKEFILE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
