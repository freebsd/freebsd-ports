# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.22
PORTREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Speed up perl CGI scripts by running them persistently

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure patch

OPTIONS_DEFINE=	APACHE
OPTIONS_DEFAULT=APACHE
APACHE_DESC=	Build mod_speedycgi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE=	22
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	APACHE="@comment "
CONFIGURE_ENV+=	WITHOUT_APACHE=yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's/__inline__//g' \
		${WRKSRC}/src/speedy_inc.h
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
