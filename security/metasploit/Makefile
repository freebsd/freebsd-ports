# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	3.2
CATEGORIES=	security
MASTER_SITES=	http://spool.metasploit.com/releases/
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

SCRIPTS=	msfcli msfconsole msfd msfselfscan msfencode msfmachscan \
		msfopcode msfpayload msfpescan msfweb

NO_BUILD=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
RUN_DEPENDS+=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems
.endif

.if defined(WITH_MSFGUI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2
SCRIPTS+=	msfgui
.endif

do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${DATADIR}
.for f in ${SCRIPTS}
	${LN} -s ${DATADIR}/${f} ${PREFIX}/bin
.endfor

post-install:
.for f in ${SCRIPTS}
	${ECHO} "bin/${f}" >> ${TMPPLIST}
.endfor
	@${FIND} ${DATADIR} -type f | ${SED} 's,${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,${PREFIX}/,, ; s,^,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
