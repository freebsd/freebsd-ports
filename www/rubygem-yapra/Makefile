# New ports collection makefile for:	rubygem-yapra
# Date created:		2008-07-30
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	yapra
PORTVERSION=	0.1.1
CATEGORIES=	www rubygems
MASTER_SITES=	RUBYFORGE

MAINTAINER=	tota@rtfm.jp
COMMENT=	Yet Another Pragger implementation

RUN_DEPENDS=	rubygem-mechanize>=0.7.6:${PORTSDIR}/www/rubygem-mechanize

USE_RUBY=	yes
USE_RUBYGEMS=	yes

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${ECHO} %%GEM_CACHE%% > pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> pkg-plist.new
	${ECHO} %%GEM_SPEC%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
