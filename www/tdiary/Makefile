# New ports collection makefile for:    tdiary
# Date created:                 21 May 2003
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	2.0.2
CATEGORIES?=	www ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.tdiary.org/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	A Web-based diary system (like weblog) written in Ruby

NO_BUILD=	yes
CONFLICTS?=	ja-tdiary-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RUBY=	yes

.if  !defined(WITHOUT_RUBY_FEATURES)
USE_RUBY_FEATURES=	fileutils
.endif

RUBY_SHEBANG_FILES=	index.rb update.rb misc/convert2.rb misc/plugin/squeeze.rb \
			misc/plugin/windex.rb \
			misc/plugin/trackback/tb.rb misc/style/etdiary/etdiary_test.rb

PLIST_FILES=	${TDIARYDIR:S|${LOCALBASE}/||}/tdiaryinst.rb
TDIARYDIR=	${EXAMPLESDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#TDIARY_LANG	ja:Japanese en:English zh:Traditional-Chinese

.if  !defined(TDIARY_LANG)
TDIARY_LANG=	en
.else
.if ${TDIARY_LANG} == "tdiary.conf-ja"
TDIARY_LANG=	ja
.endif
.endif
.if defined(WITH_TDIARY_UCONV)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif
.if defined(WITH_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.include <bsd.port.pre.mk>

.if ${RUBY_VERSION_CODE} < 167
IGNORE=		Needs ruby 1.6.7 or higher, check ruby's version and try again
.endif

do-install:
	@-${MKDIR} ${TDIARYDIR}
	@${SED} -e 's,@@@@PREFIX@@@@,${PREFIX},g' \
		-e 's,@@@@LANG@@@@,${TDIARY_LANG},g' \
		${FILESDIR}/tdiaryinst.rb.in > ${TDIARYDIR}/tdiaryinst.rb
	@${CP} -pR ${WRKSRC}/ ${TDIARYDIR}
.if ${TDIARY_LANG} == ja
	@${ECHO_MSG} "===>  TDIARY : Japanese Language messages support"
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%J]")' ${TDIARYDIR}/tdiary.conf.sample
.else
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%a]")' ${TDIARYDIR}/misc/i18n/tdiary.conf.sample-en
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TDIARYDIR}

post-install:
	@cd ${WRKSRC} && ${FIND} . -type f -o -type l | ${SED} -e 's,^\.,${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${FIND} . -type d -depth  | ${SED} -e 's,^\.,@dirrm ${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@${SED}	-e 's|%%EXAMPLESDIR%%|${EXAMPLESDIR}|' < ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
