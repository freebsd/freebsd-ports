# New ports collection makefile for:	rubygem-scrubyt
# Date created:		2007-03-13
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	scrubyt
PORTVERSION=	0.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tota@rtfm.jp
COMMENT=	A powerful web scraping toolkit written in Ruby

RUN_DEPENDS=	rubygem-mechanize>=0.6.3:${PORTSDIR}/www/rubygem-mechanize

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	${ECHO} %%GEM_CACHE%% > pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},%%GEM_DOC_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type f | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},%%GEM_LIB_DIR%%,' >> pkg-plist.new
	${ECHO} %%GEM_SPEC%% >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_LIB_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_LIB_DIR},@dirrm %%GEM_LIB_DIR%%,' >> pkg-plist.new
	${FIND} ${PREFIX}/${GEM_DOC_DIR} -type d -depth | ${SED} -e 's,${PREFIX}/${GEM_DOC_DIR},@dirrm %%GEM_DOC_DIR%%,' >> pkg-plist.new

.include <bsd.port.mk>
