# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	3.0-beta-3
CATEGORIES=	security
MASTER_SITES=	#
PKGNAMESUFFIX=	-devel
DISTNAME=	framework-${DISTVERSION}-svn

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		${LOCALBASE}/bin/gem:${PORTSDIR}/devel/ruby-gems \
		${LOCALBASE}/lib/ruby/gems/1.8/specifications/activerecord-1.15.3.gemspec:${PORTSDIR}/databases/rubygem-activerecord

SCRIPTS=	msfcli msfconsole msfd msfencode msflicense msfopcode \
		msfpayload msfpescan msfweb

WRKSRC=	${WRKDIR}/framework-${DISTVERSION}
RESTRICTED=	May not be re-sold for more than the cost of duplication, nor redistributed after patching

CONFLICTS=	metasploit-2*
NO_BUILD=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MSFWX)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/wxruby.so:${PORTSDIR}/x11-toolkits/ruby-wx
SCRIPTS+=	msfwx
PLIST_SUB+=	MSF=""
.else
PLIST_SUB+=	MSF="@comment "
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

post-extract:
	@${FIND} ${WRKSRC}/ -type d -name '.svn' | ${XARGS} ${RM} -rf

do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${DATADIR}
.for f in ${SCRIPTS}
	${LN} -s ${DATADIR}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
