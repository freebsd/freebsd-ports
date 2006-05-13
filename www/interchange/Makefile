# New ports collection makefile for:	interchange
# Date created:		2 July 2002
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	interchange
PORTVERSION=	5.4.0
CATEGORIES=	www
MASTER_SITES=	http://ftp.icdevgroup.org/interchange/5.4/tar/

MAINTAINER=	loader@freebsdmall.com
COMMENT=	RedHat's database-enabled e-commerce server

BUILD_DEPENDS=	${ARCH_PERL}/Safe/Hole.pm:${PORTSDIR}/security/p5-Safe-Hole \
		${SITE_PERL}/URI/URL.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Set/Crontab.pm:${PORTSDIR}/devel/p5-Set-Crontab \
		${SITE_PERL}/Business/OnlinePayment.pm:${PORTSDIR}/finance/p5-Business-OnlinePayment

USE_PERL5=	yes
PERL_CONFIGURE=	yes

OPTIONS=	MYSQL "Add MySQL support" off \
		PGSQL "Add PostgreSQL support" off

.include <bsd.port.pre.mk>

.if defined(WITH_MYSQL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
USE_SQLDB=	yes
.endif

.if defined(WITH_PGSQL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBD/Pg.pm:${PORTSDIR}/databases/p5-DBD-Pg
USE_SQLDB=	yes
.endif

ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

MAN1=		compile_link.1 \
		config_prog.1 \
		configdump.1 \
		crontab.1 \
		dump.1 \
		expire.1 \
		expireall.1 \
		findtags.1 \
		ic_mod_perl.1 \
		interchange.1 \
		localize.1 \
		makecat.1 \
		offline.1 \
		restart.1 \
		update.1

MAN3=		Business::Fedex.3 \
		Business::UPS.3 \
		IniConf.3 \
		Tie::ShadowHash.3 \
		Vend::Accounting::SQL_Ledger.3 \
		Vend::CounterFile.3 \
		Vend::Form.3 \
		Vend::Interpolate.3 \
		Vend::Options::Matrix.3 \
		Vend::Options::Old48.3 \
		Vend::Options::Simple.3 \
		Vend::Parser.3 \
		Vend::Payment::AuthorizeNet.3 \
		Vend::Payment::BoA.3 \
		Vend::Payment::BusinessOnlinePayment.3 \
		Vend::Payment::CyberCash.3 \
		Vend::Payment::ECHO.3 \
		Vend::Payment::EFSNet.3 \
		Vend::Payment::Ezic.3 \
		Vend::Payment::ICS.3 \
		Vend::Payment::Linkpoint.3 \
		Vend::Payment::MCVE.3 \
		Vend::Payment::PRI.3 \
		Vend::Payment::PSiGate.3 \
		Vend::Payment::Signio.3 \
		Vend::Payment::Skipjack.3 \
		Vend::Payment::TCLink.3 \
		Vend::Payment::TestPayment.3 \
		Vend::Payment::WellsFargo.3 \
		Vend::Payment::iTransact.3 \
		Vend::SOAP::Transport.3 \
		Vend::SQL_Parser.3 \
		Vend::Ship.3 \
		Vend::Ship::Postal.3 \
		Vend::Ship::QueryUPS.3 \
		Vend::Table::Editor.3 \
		Vend::UserControl.3 \
		Vend::UserDB.3

MAKE_ARGS+=	NOCPANINSTALL=1 \
		INSTALLARCHLIB=${PREFIX}/interchange/ \
		INSTALLPRIVLIB=${PREFIX}/interchange/lib/ \
		INSTALLMAN1DIR=${PREFIX}/man/man1

CONFIGURE_ARGS+=	force=1

post-patch:
	@${REINPLACE_CMD} -e "s:You are now ready to cd to \$$realdir:You are now ready to cd to ${PREFIX}:g" ${WRKSRC}/Makefile.PL

pre-configure:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} PRE-INSTALL

pre-install:
	@${MKDIR} ${PREFIX}/interchange

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/interchange.sh \
	    ${PREFIX}/etc/rc.d/interchange.sh.sample
.for i in compile_link config_prog configdump dump expire expireall interchange localize makecat offline restart update
	@${REINPLACE_CMD} -i "" -e "s:${PREFIX}:${PREFIX}/interchange:g; s:${PREFIX}/interchange/bin: ${PREFIX}/bin:g" ${PREFIX}/bin/${i}
.endfor
	@${CHOWN} -R interch:interch ${PREFIX}/interchange

.if ${PERL_LEVEL} < 500600
IGNORE=	needs perl 5.6.1 or higher, install lang/perl5.8 and try again.
.endif

.include <bsd.port.post.mk>
