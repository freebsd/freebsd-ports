# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	#
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/lib/ruby/gems/1.8/specifications/activerecord-1.15.6.gemspec:${PORTSDIR}/databases/rubygem-activerecord

SCRIPTS=	msfcli msfconsole msfd msfencode msflicense msfopcode \
		msfpayload msfpescan msfweb

RESTRICTED=	May not be re-sold for more than the cost of duplication, nor redistributed after patching

NO_BUILD=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
RUN_DEPENDS+=	${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems
.endif

.if defined(WITH_MSFGUI)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/wxruby.so:${PORTSDIR}/x11-toolkits/ruby-wx
SCRIPTS+=	msfgui
.endif

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=\n \
Due to licensing restrictions you have to accept the Metasploit Framework\n \
License before downloading ${DISTNAME}${EXTRACT_SUFX}. Please direct your\n \
web browser to http://metasploit.com/projects/Framework/msf3/ to read and\n \
accept the license. Once downloaded, save ${DISTNAME}${EXTRACT_SUFX} \n \
in ${DISTDIR} and try again.\n
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
