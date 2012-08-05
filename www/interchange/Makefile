# New ports collection makefile for:	interchange
# Date created:		2 July 2002
# Whom:			Seth Kingsley <sethk@meowfishies.com>
#
# $FreeBSD$
#

PORTNAME=	interchange
PORTVERSION=	5.6.1
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	http://ftp.icdevgroup.org/interchange/5.6/tar/

MAINTAINER=	loader@freebsdmall.com
COMMENT=	RedHat's database-enabled e-commerce server

RUN_DEPENDS=	p5-Safe-Hole>=0.10:${PORTSDIR}/security/p5-Safe-Hole \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.810:${PORTSDIR}/www/p5-libwww \
		p5-Set-Crontab>=1.00:${PORTSDIR}/devel/p5-Set-Crontab \
		p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_BZIP2=	yes
PERL_CONFIGURE=	yes

OPTIONS=	MYSQL "Add MySQL support" on \
		PGSQL "Add PostgreSQL support" off

.include <bsd.port.pre.mk>

USE_RC_SUBR=	interchange

.if defined(WITH_MYSQL)
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
.endif

.if defined(WITH_PGSQL)
RUN_DEPENDS+=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg
.endif

ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

MAN1=		compile_link.1 \
		config_prog.1 \
		configdump.1 \
		crontab.1 \
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

MAN3=		Vend::Accounting::SQL_Ledger.3 \
		Vend::Cart.3 \
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
		Vend::Payment::Getitcard.3 \
		Vend::Payment::ICS.3 \
		Vend::Payment::Linkpoint.3 \
		Vend::Payment::MCVE.3 \
		Vend::Payment::NetBilling.3 \
		Vend::Payment::Protx2.3 \
		Vend::Payment::PRI.3 \
		Vend::Payment::PSiGate.3 \
		Vend::Payment::Sage.3 \
		Vend::Payment::Signio.3 \
		Vend::Payment::Skipjack.3 \
		Vend::Payment::TCLink.3 \
		Vend::Payment::TestPayment.3 \
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
.for i in compile_link config_prog configdump expire expireall interchange localize makecat offline restart update
	@${REINPLACE_CMD} -i "" -e "s:${PREFIX}:${PREFIX}/interchange:g; s:${PREFIX}/interchange/bin: ${PREFIX}/bin:g" ${PREFIX}/bin/${i}
.endfor
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
