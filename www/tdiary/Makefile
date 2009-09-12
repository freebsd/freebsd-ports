# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	2.2.2
CATEGORIES?=	www ruby
MASTER_SITES=	http://www.tdiary.org/download/ \
		SF
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Web-based diary system (like weblog) written in Ruby

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_VER=	1.8
RUBY_REQUIRE=	Ruby >= 182
PORTSCOUT=	limitw:1,even

RUBY_SHEBANG_FILES=	index.rb \
			update.rb \
			misc/convert2.rb \
			misc/plugin/amazon/amazonimg.rb \
			misc/plugin/pingback/pb.rb \
			misc/plugin/squeeze.rb \
			misc/plugin/trackback/tb.rb \
			misc/plugin/xmlrpc/xmlrpc.rb \
			misc/style/etdiary/etdiary_test.rb \
			tdiary/wiki_style_test.rb

PORTDOCS=	ChangeLog COPYING HOWTO-make-io.rd HOWTO-make-plugin.html \
		HOWTO-make-theme.html HOWTO-use-plugin.html \
		HOWTO-write-tDiary.en.html HOWTO-write-tDiary.html INSTALL.html \
		README.en.html README.html UPGRADE doc.css

SUB_FILES=	pkg-message tdiaryinst.rb
SUB_LIST+=	TDIARY_LANG=${TDIARY_LANG} \
		TDIARY_SCRIPT=${TDIARY_SCRIPT}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${UNIQUENAME}
WWWDIR=		${PREFIX}/www/${UNIQUENAME}

TDIARY_SCRIPT=	${UNIQUENAME}-inst.rb

#TDIARY_LANG	ja:Japanese en:English zh:Traditional-Chinese
.if !defined(TDIARY_LANG) || ( defined(TDIARY_LANG) && ${TDIARY_LANG} != ja )
TDIARY_LANG=	en
.endif

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=	requires Ruby 1.8.2 or later
.endif

.if ${RUBY_VER} == 1.8
.if !defined(WITHOUT_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.endif

post-extract:
	@cd ${WRKSRC} && ${RM} -f README && ${MV} ChangeLog doc
	@cd ${WRKSRC} && ${MV} doc ${WRKDIR}

pre-install:
	@${SED} -e 's,#!/usr/bin/env ruby,#!${RUBY},' \
		${WRKDIR}/tdiaryinst.rb > ${WRKDIR}/${TDIARY_SCRIPT}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${TDIARY_SCRIPT} ${PREFIX}/bin
	@-${MKDIR} ${WWWDIR}
	@${CP} -pR ${WRKSRC}/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}' >> ${TMPPLIST}
	@${ECHO_CMD} bin/${TDIARY_SCRIPT} >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKDIR}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
