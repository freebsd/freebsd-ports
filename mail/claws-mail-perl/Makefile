# New ports collection makefile for:	sylpheed-claws-perl
# Date created:	3 April 2006
# Whom:	Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	0.9.2
CATEGORIES=	mail
MASTER_SITES=	http://claws.sylpheed.org/downloads/plugins/
PKGNAMEPREFIX=	sylpheed-claws-
DISTNAME=	perl_plugin-${PORTVERSION}

MAINTAINER=	c0rn@o2.pl
COMMENT=	Perl filtering plugin for sylpheed-claws

BUILD_DEPENDS=	sylpheed-claws>=2.1:${PORTSDIR}/mail/sylpheed-claws
RUN_DEPENDS=	sylpheed-claws>=2.1:${PORTSDIR}/mail/sylpheed-claws

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	autoconf:259
USE_PERL5=	yes

PLIST_FILES=	lib/sylpheed-claws/plugins/perl_plugin.a \
		lib/sylpheed-claws/plugins/perl_plugin.la \
		lib/sylpheed-claws/plugins/perl_plugin.so \
		share/sylpheed-claws/matcherrc2perlfilter.pl

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires newer Perl, but you can use databases/p5-DBI-137 instead
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/sylpheed-claws
	@${INSTALL_SCRIPT} ${WRKSRC}/tools/matcherrc2perlfilter.pl \
		${PREFIX}/share/sylpheed-claws/

.include <bsd.port.post.mk>
