# New ports collection makefile for:	nicotine
# Date created:				19 Aug 2003
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nicotine
PORTVERSION=	1.0.6
CATEGORIES=	net
MASTER_SITES=	http://nicotine.thegraveyard.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 SoulSeek filesharing client

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/bsddb3/__init__.py:${PORTSDIR}/databases/py-bsddb

USE_BZIP2=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if exists(${PYTHON_SITELIBDIR}/ogg/vorbis.so) || defined(WITH_VORBIS)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/ogg/vorbis.so:${PORTSDIR}/audio/py-vorbis
.else
pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define WITH_VORBIS=yes to enable OGG/Vorbis support"
	@${ECHO_MSG} ""
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.import-winconfig ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
