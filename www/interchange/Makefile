# New ports collection makefile for:	interchange
# Date created:		2 July 2002
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	interchange
PORTVERSION=	4.8.7
CATEGORIES=	www
MASTER_SITES=	http://ftp.icdevgroup.org/interchange/4.8/tar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RedHat's database-enabled e-commerce server

BUILD_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement

RUN_DEPENDS=	${SITE_PERL}/SQL/Statement.pm:${PORTSDIR}/databases/p5-SQL-Statement \
	${ARCH_PERL}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
	${ARCH_PERL}/Safe/Hole.pm:${PORTSDIR}/security/p5-Safe-Hole \
	${ARCH_PERL}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
	${ARCH_PERL}/MIME/Base64.pm:${PORTSDIR}/mail/p5-MIME-Tools \
	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
	${SITE_PERL}/Term/ReadLine/Perl.pm:${PORTSDIR}/devel/p5-ReadLine-Perl \
	${ARCH_PERL}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey

USE_PERL5=	yes
PERL_CONFIGURE=	yes
ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

MAN1=		configdump.1 config_prog.1 expire.1 localize.1 \
		makecat.1 dump.1 compile_link.1 offline.1 update.1 \
		restart.1 expireall.1 interchange.1
MAN7=		iccattut.7 icdatabase.7 icadvanced.7 icconfig.7 \
		icfoundation.7 icfaq.7 ic_howto_cvs.7 icupgrade.7 \
		ic_ecommerce.7 ictags.7 ictemplates.7

USE_REINPLACE=	yes

MAKE_ARGS+=	NOCPANINSTALL=1 \
		INSTALLARCHLIB=${PREFIX}/interchange \
		INSTALLPRIVLIB=${PREFIX}/interchange/lib/ \
		INSTALLMAN1DIR=${PREFIX}/man/man1 \
		INSTALLMAN3DIR=${PREFIX}/man/man7

CONFIGURE_ARGS+=	force=1

.if defined(PACKAGE_BUILDING)
IGNORE="needs a tty at the configure stage"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s:You are now ready to cd to \$$realdir:You are now ready to cd to ${PREFIX}:g" ${WRKSRC}/Makefile.PL

pre-configure:
.if !defined(USE_THIS_PERL)
	@[ ! "${PERL_VER}" \< "5.6.1" ] || ( ${ECHO_CMD} -e "You use perl ${PERL_VER}, interchange should be used with 5.6.1 or better,\njust install the newer perl from ports and run 'use.perl port', this will\nmake the new perl the default perl. If you already have some perl modules\ninstalled for your old perl, you have to reinstall them for the new perl.\n\nIf you absolutely want to try to run interchange with perl ${PERL_VER},\nyou have to add '-DUSE_THIS_PERL' as an option for 'make'.\n" ; exit 1 )
.endif
.if !defined(CHECK_FOR_IC_USER)
	@${ECHO_CMD} -e "This port needs a specific user account ('interch') at configure time.\n\nIf it is ok for you to add a new user at configure time of this port\nadd '-DCHECK_FOR_IC_USER' as an option for 'make'.\n"
	@exit 1
.endif
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/interchange.sh \
	    ${PREFIX}/etc/rc.d/interchange.sh.sample
	@${REINPLACE_CMD} -i "" -e 's:%%PREFIX%%:${PREFIX}:' \
	    ${PREFIX}/etc/rc.d/interchange.sh.sample
.for i in compile_link config_prog configdump dump expire expireall interchange localize makecat offline restart update
	@${REINPLACE_CMD} -i "" -e "s:${PREFIX}:${PREFIX}/interchange:g; s:${PREFIX}/interchange/bin: ${PREFIX}/bin:g" ${PREFIX}/bin/${i}
.endfor
	@${CHOWN} -R interch:interch ${PREFIX}/interchange/src

.include <bsd.port.mk>
