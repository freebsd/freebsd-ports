# New ports collection makefile for:	x11-fm/p5-PerlFM
# Date created:		2009-10-19
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	PerlFM
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	x11-fm perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/V/VV/VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	A Perl based file manager

RUN_DEPENDS=	p5-Gtk2>=1.060:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Chmod>=0.0.0:${PORTSDIR}/x11-toolkits/p5-Gtk2-Chmod \
		p5-Gtk2-PathButtonBar>=0.1.2:${PORTSDIR}/x11-toolkits/p5-Gtk2-PathButtonBar \
		p5-String-ShellQuote>=1.03:${PORTSDIR}/textproc/p5-String-ShellQuote \
		p5-File-Stat-Bits>=1.01:${PORTSDIR}/sysutils/p5-File-Stat-Bits \
		p5-ZConf-Bookmarks>=0.2.3:${PORTSDIR}/net/p5-ZConf-Bookmarks \
		p5-ZConf-Runner>=2.1.1:${PORTSDIR}/deskutils/p5-ZConf-Runner \
		p5-Dir-Watch>=0.0.0:${PORTSDIR}/devel/p5-Dir-Watch

PERL_CONFIGURE=	yes

MAN3=		PerlFM.3

.include <bsd.port.mk>
