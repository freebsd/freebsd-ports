# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	metasploit
DISTVERSION=	4.5.0
CATEGORIES=	security
MASTER_SITES=	http://downloads.metasploit.com/data/releases/
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	tanawts@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	nasm:${PORTSDIR}/devel/nasm				\
		nmap:${PORTSDIR}/security/nmap

WRKSRC=		${WRKDIR}/msf3
SCRIPTS=	msfcli msfconsole msfd msfelfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

OPTIONS_DEFINE=	SVN

NO_BUILD=	yes
USES=		ncurses:port
USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.8
RUN_DEPENDS+=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems
.else
RUN_DEPENDS+=	rubygem-actionpack>0:${PORTSDIR}/www/rubygem-actionpack	\
		rubygem-sqlite3>0:${PORTSDIR}/databases/rubygem-sqlite3	\
		rubygem-activerecord>0:${PORTSDIR}/databases/rubygem-activerecord \
		rubygem-activesupport>0:${PORTSDIR}/devel/rubygem-activesupport
.endif

.if ${PORT_OPTIONS:MSVN}
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
	@${FIND} ${DATADIR} -type l | ${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
