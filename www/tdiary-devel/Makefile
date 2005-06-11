# New ports collection makefile for:    tdiary-devel
# Date created:                 9 June 2005
# Whom:                         Fumihiko Kimura <jfkimura@yahoo.co.jp>
#
# $FreeBSD$
#

PORTNAME=	tdiary
PORTVERSION=	2.1.1
CATEGORIES?=	www ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.tdiary.org/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-full-${PORTVERSION}

MAINTAINER=	jfkimura@yahoo.co.jp
COMMENT=	A Web-based diary system (like weblog) written in Ruby

NO_BUILD=	yes
CONFLICTS?=	ja-tdiary-devel-[0-9]*
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_RUBY=	yes
RUBY_VER=	1.8

RUBY_SHEBANG_FILES=	index.rb update.rb misc/convert2.rb misc/plugin/squeeze.rb \
			misc/plugin/windex.rb misc/plugin/rast-register.rb \
			misc/plugin/trackback/tb.rb misc/style/etdiary/etdiary_test.rb \
			misc/plugin/pingback/pb.rb misc/plugin/xmlrpc/xmlrpc.rb

PLIST_FILES=	${TDIARYDIR:S|${LOCALBASE}/||}/tdiaryinst.rb
TDIARYDIR=	${EXAMPLESDIR}${PKGNAMESUFFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if  !defined(TDIARY_LANG)
TDIARY_LANG=	tdiary.conf-en
.endif
.if defined(WITH_TDIARY_UCONV)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/uconv.so:${PORTSDIR}/japanese/ruby-uconv
.endif
.if defined(WITH_TDIARY_NORA)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/web/escape_ext.so:${PORTSDIR}/www/ruby-nora
.endif
.include <bsd.port.pre.mk>

.if ${RUBY_VERSION_CODE} < 182
IGNORE=		Needs ruby 1.8.2 or higher, install lang/ruby18 and try again
.endif

do-install:
	@-${MKDIR} ${TDIARYDIR}
	@${SED} -e 's,@@@@PREFIX@@@@,${PREFIX},g' \
		-e 's,@@@@TDIARY@@@@,${PORTNAME}${PKGNAMESUFFIX},g' \
		-e 's,@@@@LANG@@@@,${TDIARY_LANG},g' \
		${FILESDIR}/tdiaryinst.rb.in > ${TDIARYDIR}/tdiaryinst.rb
	@${CP} -pR ${WRKSRC}/ ${TDIARYDIR}
.if ${TDIARY_LANG} == tdiary.conf-en
	@${ECHO_MSG} "===>  TDIARY : English Language messages support"
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%a]")' ${TDIARYDIR}/misc/i18n/tdiary.conf.sample-en
.else
	@${ECHO_MSG} "===>  TDIARY : Japanese Language messages support"
	@${RUBY} -i -pe 'sub(/%Y-%m-%d/, "%Y-%m-%d [%J]")' ${TDIARYDIR}/tdiary.conf.sample
	@${ECHO_MSG}
	@${ECHO_MSG} "===>  When you install in home directory, let's choose plugin of 'jdate.rb' to just display 'YOUBI'."
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${TDIARYDIR}

post-install:
	@cd ${WRKSRC} && ${FIND} . -type f -o -type l | ${SED} -e 's,^\.,${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@cd ${WRKSRC} && ${FIND} . -type d -depth  | ${SED} -e 's,^\.,@dirrm ${TDIARYDIR:S|${LOCALBASE}/||},' >> ${TMPPLIST}
	@${SED}	-e 's|%%EXAMPLESDIR%%|${TDIARYDIR}|' < ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
