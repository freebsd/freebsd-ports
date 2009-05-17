# Ports collection makefile for:    clive-utils
# Date created:    7 February 2009
# Whom:            bf <bf2006a@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	clive-utils
PORTVERSION=	2.1.6
CATEGORIES=	multimedia net perl5
MASTER_SITES=	GOOGLE_CODE
DIST_SUBDIR=	clive

MAINTAINER=	legatvs@gmail.com
COMMENT=	Passwords, RSS parsing, and link extraction for clive

NO_BUILD=	yes
USE_PERL5_RUN=	5.8.2+
USE_BZIP2=	yes
USE_GMAKE=	yes

RUN_DEPENDS+=	clive>=2.0:${PORTSDIR}/multimedia/clive \
		p5-Crypt-PasswdMD5>=1.3:${PORTSDIR}/security/p5-Crypt-PasswdMD5 \
		p5-Crypt-Twofish>=2.12:${PORTSDIR}/security/p5-Crypt-Twofish \
		p5-XML-RSS-LibXML>=0.30.02:${PORTSDIR}/textproc/p5-XML-RSS-LibXML \
		p5-HTML-Strip>=1.06:${PORTSDIR}/www/p5-HTML-Strip \
		p5-Tk>=804.028.501:${PORTSDIR}/x11-toolkits/p5-Tk

PLIST_FILES=	bin/clivefeed bin/clivepass bin/clivescan

OPTIONS=	PASTE "Enable pasting of URLs from X clipboard" Off \
		FONTDIALOG "Enable Font Dialog support" Off \
		MANPAGES "Install manual pages" On

.include <bsd.port.pre.mk>

.ifdef WITH_PASTE
RUN_DEPENDS+=	p5-Clipboard>=0.09:${PORTSDIR}/x11/p5-Clipboard
.endif

.ifdef WITH_FONTDIALOG
RUN_DEPENDS+=	p5-Tk-FontDialog>=0.15:${PORTSDIR}/x11-toolkits/p5-Tk-FontDialog
.endif

.ifdef WITH_MANPAGES && !defined(NO_INSTALL_MANPAGES)
MAKE_ENV=	WITH_MAN=yes
MAN1=		clivefeed.1 clivepass.1 clivescan.1
.endif

.include <bsd.port.post.mk>
