# New ports collection makefile for:	wmlongrun
# Date created:				Sat Mar 23 21:00:03 EST 2002
# Whom:					pat
#
# $FreeBSD$
#

PORTNAME=	wmlongrun
PORTVERSION=	0.2.0
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/

MAINTAINER=	pat@FreeBSD.org

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_XPM=	yes

MAN1=		wmlongrun.1

pre-patch:
.for dir in src doc .
	@${PERL} -pi -e 's|\@program_transform_name\@||' \
		${WRKSRC}/${dir}/Makefile.in
.endfor

.ifndef(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
