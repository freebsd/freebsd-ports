# New ports collection makefile for:	opendchub
# Date created:			May 29, 2002
# Whom:				Munish Chopra <mchopra@engmail.uwaterloo.ca>
#
# $FreeBSD$
#

PORTNAME=	opendchub
PORTVERSION=	0.6.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	Unofficial Unix version of the Direct Connect Hub software

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

DOC_FILES=	COPYING README

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
