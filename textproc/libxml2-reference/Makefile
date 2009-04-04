# New ports collection makefile for:	libxml2-reference
# Date created:				09 May 2006
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0

BUILD_DEPENDS=	${NONEXISTENT}:${.CURDIR}/../libxml2:configure

PARENT_WRKSRC!=	cd ${.CURDIR}/../libxml2 && ${MAKE} -V WRKSRC
EXTRACT_ONLY=
USE_GMAKE=	yes

.if !defined(NOPORTEXAMPLES)
EXAMPLES=	testHTML.c testSAX.c testXPath.c xmllint.c
PLIST_FILES=	${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

do-install:
.if !defined(NOPORTDOCS)
.for d in . doc doc/devhelp doc/examples
	@cd ${PARENT_WRKSRC}/${d} && ${GMAKE} install-data-local
.endfor
.endif

.include "${.CURDIR}/../../devel/glib20-reference/bsd.gnome-reference.mk"
