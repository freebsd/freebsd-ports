# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	2.2.1
CATEGORIES?=	www ruby
MASTER_SITES=	http://www.tdiary.org/download/ \
		SF
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	tota@rtfm.jp
COMMENT=	A Web-based diary system (like weblog) written in Ruby

NO_BUILD=	yes
CONFLICTS?=	tdiary-devel-[0-9]* \
		ja-tdiary-[0-9]* \
		ja-tdiary-devel-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RUBY=	yes

RUBY_SHEBANG_FILES=	index.rb update.rb misc/convert2.rb \
			misc/plugin/amazon/amazonimg.rb misc/plugin/pingback/pb.rb \
			misc/plugin/squeeze.rb misc/plugin/trackback/tb.rb \
			misc/plugin/xmlrpc/xmlrpc.rb misc/style/etdiary/etdiary_test.rb \
			tdiary/wiki_style_test.rb

PORTDOCS=	ChangeLog COPYING HOWTO-make-io.rd HOWTO-make-plugin.html \
		HOWTO-make-theme.html HOWTO-use-plugin.html \
		HOWTO-write-tDiary.en.html HOWTO-write-tDiary.html INSTALL.html \
		README.en.html README.html UPGRADE doc.css

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#TDIARY_LANG	ja:Japanese en:English zh:Traditional-Chinese
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif
.if defined(WITH_TDIARY_UCONV)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif
.if !defined(WITHOUT_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f README && ${MV} ChangeLog doc
	@cd ${WRKSRC} && ${MV} doc ${WRKDIR}

do-install:
	@-${MKDIR} ${EXAMPLESDIR}
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		-e 's,@@@@PREFIX@@@@,${PREFIX},g' \
		-e 's,@@@@LANG@@@@,${TDIARY_LANG},g' \
		${FILESDIR}/tdiaryinst.rb.in > ${EXAMPLESDIR}/tdiaryinst.rb
	@${CP} -pR ${WRKSRC}/ ${EXAMPLESDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
	@${CHMOD} 755 ${EXAMPLESDIR}
	@${ECHO_CMD} '@exec ${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}' \
		>> ${TMPPLIST}

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKDIR}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
