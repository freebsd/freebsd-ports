PORTNAME=	hxtools
PORTVERSION=	20211204
CATEGORIES=	misc
MASTER_SITES=	http://inai.de/files/hxtools/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of miscellaneous tools and scripts

LIB_DEPENDS=	libHX.so:lang/libhx libpci.so:devel/libpci
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang iconv perl5 pkgconfig shebangfix \
		tar:xz xorg
GNU_CONFIGURE=	yes
SHEBANG_FILES=	data/hxtools_bashrc.bash data/hxtools_profile.bash \
		examples/colortable examples/git-deconstruct examples/neon \
		examples/rc4 examples/unitable sadmin/hxnetload \
		sadmin/ldif-duplicate-attrs sadmin/ldif-leading-spaces \
		sadmin/logontime sadmin/pmap_dirty sadmin/recursive_lower \
		sadmin/vcsaview sdevel/checkbrack sdevel/cwdiff \
		sdevel/diff2php sdevel/doxygen-kerneldoc-filter \
		sdevel/git-author-stat sdevel/git-blame-stats \
		sdevel/git-forest sdevel/git-revert-stats \
		sdevel/git-track sdevel/man2html sdevel/paddrspacesize \
		sdevel/proc_stat_signal_decode sdevel/sourcefuncsize \
		sdevel/spec-beautifier smm/aumeta smm/extract_d3pkg \
		smm/extract_dfqshared.pm smm/extract_dxhog \
		smm/extract_f3pod smm/extract_qupak smm/gpsh smm/mkvappend \
		smm/mod2opus smm/ssa2srt suser/fxterm suser/mailsplit \
		suser/pegrep suser/pesubst suser/qpdecode suser/qtar \
		suser/rezip suser/wktimer
USE_PERL5=	run
USE_XORG=	xcb

CONFLICTS_INSTALL=	grx psptoolchain-pspsdk-stage2 # bin/bin2c

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -E 's,(/usr)?/bin,${LOCALBASE}/bin,g' \
		${WRKSRC}/sadmin/su1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/changelog.rst ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
