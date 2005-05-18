# ex: ts=8 sts=0 noet
# New ports collection makefile for:	Mathomatic
# Date created:			Tue Mar 22 10:05:25 CET 2005
# Whom:				Roman Neuhauser <neuhauser@sigpipe.cz>
#
# $FreeBSD$
#

PORTNAME=	mathomatic
PORTVERSION=	12.3.2
CATEGORIES=	math
MASTER_SITES=	http://www.panix.com/~gesslein/
EXTRACT_SUFX=	.tgz

MAINTAINER=	neuhauser@sigpipe.cz
COMMENT=	Highly portable, general purpose CAS (Computer Algebra System)

DISTVERSION=	${PORTVERSION:C/\.([[:alpha:]]+)/\1/}
WRKSRC=		${WRKDIR}/${DISTNAME}
MAKEFILE=	makefile
MAKE_ARGS+=	-DREADLINE prefix=${PREFIX} docdir='$$(prefix)/share/doc'
USE_REINPLACE=	yes

PLIST_FILES=	bin/mathomatic
PORTDOCS=	am.htm ctips.html index.html manual.htm notes.htm changes.txt

MAN1=		mathomatic.1

pre-configure:
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|#%%PORTDOCS%%|	|" ${WRKSRC}/makefile
.endif

.include <bsd.port.mk>
