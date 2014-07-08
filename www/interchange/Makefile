# Created by: Seth Kingsley <sethk@meowfishies.com>
# $FreeBSD$

PORTNAME=	interchange
PORTVERSION=	5.6.1
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	http://ftp.icdevgroup.org/interchange/5.6/tar/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RedHat's database-enabled e-commerce server

RUN_DEPENDS=	p5-Safe-Hole>=0.10:${PORTSDIR}/security/p5-Safe-Hole \
		p5-URI>=1.37:${PORTSDIR}/net/p5-URI \
		p5-libwww>=5.810:${PORTSDIR}/www/p5-libwww \
		p5-Set-Crontab>=1.00:${PORTSDIR}/devel/p5-Set-Crontab \
		p5-Digest-SHA1>=2.11:${PORTSDIR}/security/p5-Digest-SHA1
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5 tar:bzip2
USE_PERL5=	configure fixpacklist

OPTIONS_DEFINE=		MYSQL PGSQL
OPTIONS_DEFAULT=	MYSQL
MYSQL_RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
PGSQL_RUN_DEPENDS=	p5-DBD-Pg>=0:${PORTSDIR}/databases/p5-DBD-Pg

GROUPS=		interch
USERS=		interch
USE_RC_SUBR=	interchange

INTERCH_PREFIX=	${PREFIX}/interchange

# Basically the parts of CONFIGURE_ARGS that interest us without
# Uses/perl5.mk's overriding of PREFIX, INSTALLARCHLIB and INSTALLPRIVLIB,
# since we install into a custom location.
INTERCH_CONFIGURE_ARGS=	INSTALLDIRS=site \
			INTERCHANGE_USER=interch \
			PREFIX=${INTERCH_PREFIX} \
			force=1
MAKE_ARGS=		NOCPANINSTALL=1

pre-install:
# This directory must exist before the installation happens, otherwise _uid (a
# file) will be copied to a file called ${STAGEDIR}${INTERCH_PREFIX}.
	${MKDIR} ${STAGEDIR}${INTERCH_PREFIX}

do-configure:
# The same as the do-configure stage in Uses/perl5.mk, except we use
# INTERCH_CONFIGURE_ARGS instead of CONFIGURE_ARGS.
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${PERL5} ./${CONFIGURE_SCRIPT} ${INTERCH_CONFIGURE_ARGS}

post-install:
# This directory has to be created here for check-plist to pass, otherwise it
# complains the @dirrmtry /var/run/interchange entry does not have a matching
# directory in the stage tree.
# Its ownership and mode are properly set in the @exec call when the package is
# installed.
	${MKDIR} ${STAGEDIR}/var/run/interchange

.include <bsd.port.mk>
