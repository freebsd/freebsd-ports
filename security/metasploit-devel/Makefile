# Ports collection makefile for:	metasploit-devel
# Date created:				18 Nov 2004
# Whom:					Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
DISTVERSION=	3.0-beta-1
CATEGORIES=	security
MASTER_SITES=	#
PKGNAMESUFFIX=	-devel
DISTNAME=	framework-${DISTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

NO_CDROM=	May not be re-sold for more than the cost of duplication
NO_PACKAGE=	May not be redistributed after patching
CONFLICTS=	metasploit-2*
NO_BUILD=	yes
USE_RUBY=	yes

SCRIPTS=	msfcli msfconsole msfd msfencode msflicense msfopcode \
		msfpayload msfpescan msfweb msfwx

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
