# New ports collection makefile for:	CGI-SpeedyCGI
# Date created:				Sun Mar 10 16:44:06 CET 2002
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.22
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Speed up perl CGI scripts by running them persistently

MAKE_JOBS_UNSAFE=	yes
PERL_CONFIGURE=	yes

OPTIONS=	APACHE "Enable mod_speedycgi" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_APACHE)
USE_APACHE=	1.3+
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
CONFIGURE_ENV+=	WITHOUT_APACHE=yes
.endif

post-patch:
	@${PERL} -pi -e 's,apxs -q,${APXS} -q,;' \
		${WRKSRC}/src/SpeedyMake.pl
	@${PERL} -pi -e 's,APXS=apxs,APXS=${APXS},;' \
		${WRKSRC}/mod_speedycgi/Makefile.tmpl
	${CP} ${FILESDIR}/speedy_dump.c ${WRKSRC}/speedy_dump/
.if ${PERL_LEVEL} >= 501000
	@${REINPLACE_CMD} -i '' -e 's=New(123,=Newx(=g' \
		${WRKSRC}/src/speedy_backend_main.h
.endif

post-configure:
	@${PERL} -pi -e 's,^PREFIX = /usr$$,PREFIX = ${PREFIX},g;' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile

post-build:
	@cd ${WRKSRC}/speedy_dump && ${CC} ${CFLAGS} -o speedy_dump \
		-I../src speedy_dump.c

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy/speedy ${PREFIX}/bin/speedy_suidperl
	@${CHMOD} 4755 ${PREFIX}/bin/speedy_suidperl
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy_dump/speedy_dump \
		${PREFIX}/bin/speedy_dump

.include <bsd.port.post.mk>
