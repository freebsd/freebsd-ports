# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	4.0.0
CATEGORIES=	security
MASTER_SITES=	http://downloads.metasploit.com/data/releases/
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	nasm:${PORTSDIR}/devel/nasm				\
		nmap:${PORTSDIR}/security/nmap

WRKSRC=		${WRKDIR}/msf3
SCRIPTS=	msfcli msfconsole msfd msfelfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

OPTIONS=	MSFGUI "Build GUI scripts" off \
		SVN "Use subversion" off \
		SVN_FBSD "Use subversion-freebsd" off

NO_BUILD=	yes
USE_RUBY=	yes
USE_BZIP2=	yes
USE_NCURSES=	yes
WITH_NCURSES_PORT=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
RUN_DEPENDS+=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems
.else
RUN_DEPENDS+=	rubygem-actionpack>0:${PORTSDIR}/www/rubygem-actionpack	\
		rubygem-sqlite3>0:${PORTSDIR}/databases/rubygem-sqlite3	\
		rubygem-activerecord>0:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-activesupport>0:${PORTSDIR}/devel/rubygem-activesupport \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
.endif

.if defined(WITH_MSFGUI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2
SCRIPTS+=	msfgui
.endif

.if defined(WITH_SVN) || defined(WITH_SVN_FBSD)
.if defined(WITH_SVN_FBSD)
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion-freebsd
.else
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
.endif
.endif

do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${DATADIR}
.for f in ${SCRIPTS}
	${LN} -s ${DATADIR}/${f} ${PREFIX}/bin/${f}
.endfor

post-install:
.for f in ${SCRIPTS}
	${ECHO} "bin/${f}" >> ${TMPPLIST}
.endfor
	@${FIND} ${DATADIR} -type f | ${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
