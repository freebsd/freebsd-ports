# Ports collection makefile for:  metasploit
# Date created:			  18 Nov 2004
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	metasploit
PORTVERSION=	2.4
CATEGORIES=	security
MASTER_SITES=	http://www.metasploit.org/tools/
DISTNAME=	framework-${PORTVERSION}

MAINTAINER=	onatan@gmail.com
COMMENT=	Exploit-Framework for Penetration-Testing

RUN_DEPENDS=	${SITE_PERL}/mach/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu	\
		${SITE_PERL}/mach/Net/SSLeay.pm:${PORTSDIR}/security/p5-Net-SSLeay \
		${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

NO_BUILD=	yes
USE_PERL5_RUN=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl version 5.6.0 or higher.
.endif

do-install:
	${MKDIR} ${DATADIR}
	${CP} -Rp ${WRKSRC}/ ${DATADIR}
.	for i in msfcli msfconsole msfelfscan msfencode msflogdump msfpayload msfpescan msfupdate msfweb
		${LN} -s ${DATADIR}/$i ${PREFIX}/bin
.	endfor

.include <bsd.port.post.mk>
