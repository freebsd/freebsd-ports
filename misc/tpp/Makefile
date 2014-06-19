# Created by: arved
# $FreeBSD$

PORTNAME=	tpp
PORTVERSION=	1.3.1
CATEGORIES=	misc
MASTER_SITES=	http://synflood.at/tpp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text presentation program

RUN_DEPENDS=	${RUBY_SITELIBDIR}/ncurses.rb:${PORTSDIR}/devel/ruby-ncurses \
		figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	yes
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

post-patch:
	@${REINPLACE_CMD} -E -e 's,share/man,man,' \
		-e 's,(DOC|INS|MAN)PATH),DESTDIR)$$(&,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
