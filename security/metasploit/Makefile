# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	3.3.3
CATEGORIES=	security
MASTER_SITES=	http://www.metasploit.com/releases/
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	infocmp:${PORTSDIR}/devel/ncurses			\
		nasm:${PORTSDIR}/devel/nasm				\
		nmap:${PORTSDIR}/security/nmap

WRKSRC=		${WRKDIR}/msf3
SCRIPTS=	msfcli msfconsole msfd msfelfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

NO_BUILD=	yes
USE_RUBY=	yes
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
RUN_DEPENDS+=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems
.else
RUN_DEPENDS+=	rubygem-actionpack:${PORTSDIR}/www/rubygem-actionpack	\
		rubygem-sqlite3:${PORTSDIR}/databases/rubygem-sqlite3	\
		rubygem-activerecord:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-activesupport:${PORTSDIR}/devel/rubygem-activesupport \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv
.endif

.if defined(WITH_MSFGUI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2
SCRIPTS+=	msfgui
.endif

.if defined(WITH_SVN)
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
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
