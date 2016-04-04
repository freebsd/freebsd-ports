# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	PerlFM
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	x11-fm perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Perl based file manager

BUILD_DEPENDS=	p5-Gtk2>=1.060:x11-toolkits/p5-Gtk2 \
		p5-Gtk2-Chmod>=0.0.0:x11-toolkits/p5-Gtk2-Chmod \
		p5-Gtk2-PathButtonBar>=0.1.2:x11-toolkits/p5-Gtk2-PathButtonBar \
		p5-String-ShellQuote>=1.03:textproc/p5-String-ShellQuote \
		p5-File-Stat-Bits>=1.01:sysutils/p5-File-Stat-Bits \
		p5-ZConf-Bookmarks>=0.2.3:net/p5-ZConf-Bookmarks \
		p5-ZConf-Runner>=2.1.1:deskutils/p5-ZConf-Runner \
		p5-Dir-Watch>=0.0.0:devel/p5-Dir-Watch
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/pfm
USE_PERL5=	configure

.include <bsd.port.mk>
