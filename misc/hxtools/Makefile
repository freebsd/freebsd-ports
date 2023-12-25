PORTNAME=	hxtools
PORTVERSION=	20231224
CATEGORIES=	misc
MASTER_SITES=	http://inai.de/files/hxtools/ \
		https://codeberg.org/jengelh/hxtools/releases/download/rel-${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of miscellaneous tools and scripts
WWW=		https://inai.de/projects/hxtools/

LICENSE=	GPLv2+ LGPL21+ MIT
LICENSE_COMB=	multi

LIB_DEPENDS=	libHX.so:lang/libhx libpci.so:devel/libpci
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang iconv perl5 pkgconfig shebangfix \
		tar:zst xorg
GNU_CONFIGURE=	yes
SHEBANG_FILES=	data/hxtools_bashrc.bash data/hxtools_profile.bash \
		examples/git-deconstruct examples/rc4 sadmin/hxnetload \
		sadmin/ldif-duplicate-attrs sadmin/ldif-leading-spaces \
		sadmin/logontime sadmin/pmap_dirty sadmin/recursive_lower \
		sadmin/vcsaview sdevel/cwdiff \
		sdevel/diff2php sdevel/doxygen-kerneldoc-filter \
		sdevel/gh-trim-workflowruns \
		sdevel/git-author-stat sdevel/git-blame-stats \
		sdevel/git-forest sdevel/git-revert-stats \
		sdevel/git-track sdevel/man2html sdevel/paddrspacesize \
		sdevel/proc_stat_signal_decode sdevel/sourcefuncsize \
		sdevel/spec-beautifier smm/aumeta smm/extract_d3pkg \
		smm/extract_dfqshared.pm smm/extract_dxhog \
		smm/extract_f3pod smm/extract_qupak smm/gpsh smm/mkvappend \
		smm/mod2opus smm/ssa2srt suser/fxterm suser/mailsplit \
		suser/pegrep suser/pesubst suser/qpdecode suser/qtar \
		suser/rezip suser/wktimer suser/xmlformat
USE_PERL5=	run
USE_XORG=	xcb

CONFLICTS_INSTALL=	grx psptoolchain-pspsdk-stage2 # bin/bin2c

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/COMPAT_PROC/s,/compat/linux,${LINUXBASE},' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -E '/COMPAT_PROC ?=/s,"","${LINUXBASE}",' \
		${WRKSRC}/sadmin/hxnetload \
		${WRKSRC}/sadmin/pmap_dirty \
		${WRKSRC}/sdevel/paddrspacesize
	@${REINPLACE_CMD} -E 's,(/usr)?/bin,${LOCALBASE}/bin,g' \
		${WRKSRC}/sadmin/su1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/changelog.rst ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
