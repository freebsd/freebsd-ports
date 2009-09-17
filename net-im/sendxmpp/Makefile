# New ports collection makefile for:	sendxmpp
# Date created:				24 Jan 2006
# Whom:	      				Max E. Kuznecov <mek@mek.uz.ua>
#
# $FreeBSD$
#

PORTNAME=	sendxmpp
PORTVERSION=	0.0.8
PORTREVISION=	1
CATEGORIES=	net-im perl5
MASTER_SITES=	http://www.djcbsoftware.nl/code/sendxmpp/

MAINTAINER=	mek@mek.uz.ua
COMMENT=	Perl-script to send xmpp (jabber) messages

RUN_DEPENDS+=	p5-Net-XMPP>0.0:${PORTSDIR}/net-im/p5-Net-XMPP \
		p5-IO-Socket-SSL>0.0:${PORTSDIR}/security/p5-IO-Socket-SSL

PERL_CONFIGURE=	yes

MAN1=	sendxmpp.1

PLIST_FILES=	bin/sendxmpp \
		%%SITE_PERL%%/mach/auto/sendxmpp/.packlist
PLIST_DIRS=	%%SITE_PERL%%/mach/auto/sendxmpp

.include <bsd.port.mk>
