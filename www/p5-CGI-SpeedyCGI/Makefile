PORTNAME=	CGI-SpeedyCGI
PORTVERSION=	2.22
PORTREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Speed up perl CGI scripts by running them persistently

LICENSE=	GPLv2

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure patch

OPTIONS_DEFINE=	APACHE
OPTIONS_DEFAULT=APACHE
APACHE_DESC=	Build mod_speedycgi

OPTIONS_SUB=	yes
APACHE_USE=	APACHE=22+
APACHE_CONFIGURE_ENV_OFF=	WITHOUT_APACHE=yes

post-patch:
	@${REINPLACE_CMD} -e 's/__inline__//g' \
		${WRKSRC}/src/speedy_inc.h
	@${PERL} -pi -e 's,apxs -q,${APXS} -q,;' \
		${WRKSRC}/src/SpeedyMake.pl
	@${PERL} -pi -e 's,APXS=apxs,APXS=${APXS},;' \
		${WRKSRC}/mod_speedycgi/Makefile.tmpl
	${CP} ${FILESDIR}/speedy_dump.c ${WRKSRC}/speedy_dump/
	@${REINPLACE_CMD} -i '' -e 's=New(123,=Newx(=g' \
		${WRKSRC}/src/speedy_backend_main.h
	${REINPLACE_CMD} -e 's|@APXS_STAGE@|-S LIBEXECDIR=${STAGEDIR}${PREFIX}/${APACHEMODDIR}|' \
		${WRKSRC}/mod_speedycgi/Makefile.tmpl

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}

post-configure:
	@${PERL} -pi -e 's,^PREFIX = /usr$$,PREFIX = ${PREFIX},g;' \
		${WRKSRC}/Makefile ${WRKSRC}/*/Makefile

post-build:
	@(cd ${WRKSRC}/speedy_dump && ${CC} ${CFLAGS} -o speedy_dump \
		-I../src speedy_dump.c)

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy/speedy ${STAGEDIR}${PREFIX}/bin/speedy_suidperl
	@${CHMOD} 4755 ${STAGEDIR}${PREFIX}/bin/speedy_suidperl
	@${INSTALL_PROGRAM} ${WRKSRC}/speedy_dump/speedy_dump \
		${STAGEDIR}${PREFIX}/bin/speedy_dump

.include <bsd.port.mk>
