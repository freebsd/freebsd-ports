# New ports collection makefile for:	sylpheed-claws-perl
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	0.9.6
CATEGORIES=	mail
MASTER_SITES=	http://www.claws-mail.org/downloads/plugins/
PKGNAMEPREFIX=	claws-mail-
DISTNAME=	perl_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Perl filtering plugin for claws-mail

BUILD_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail
RUN_DEPENDS=	claws-mail>=2.6:${PORTSDIR}/mail/claws-mail

USE_GMAKE=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autoconf:259
USE_PERL5=	yes

PLIST_FILES=	lib/claws-mail/plugins/perl_plugin.a \
		lib/claws-mail/plugins/perl_plugin.la \
		lib/claws-mail/plugins/perl_plugin.so \
		share/claws-mail/matcherrc2perlfilter.pl

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires newer Perl, but you can use databases/p5-DBI-137 instead
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/claws-mail
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/matcherrc2perlfilter.pl \
		${PREFIX}/share/claws-mail/

.include <bsd.port.post.mk>
