# New ports collection makefile for:	p5-Apache
# Version required:			0.98
# Date created:				April 26th 1997
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
#   $Id: Makefile,v 1.4 1997/05/26 01:56:54 asami Exp $
#

DISTNAME=	mod_perl-0.98
PKGNAME=	p5-Apache-0.98
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache

MAINTAINER=	jfitz@FreeBSD.ORG

USE_PERL5=	YES

CONFIGURE_ENV=	PORTSDIR=${PORTSDIR} INSTALL_PROGRAM="${INSTALL_PROGRAM}"

MAN3=		Apache.3 Apache::Constants.3  Apache::Options.3 \
		Apache::Registry.3  Apache::Status.3  Bundle::Apache.3 \
		Apache::Debug.3 mod_perl.3
MANPREFIX=	${PREFIX}/lib/perl5

pre-configure:
		@ cd ${PORTSDIR}/www/apache && ${MAKE} clean patch

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} ${PREFIX}/bin/perl Makefile.PL

post-install:
		${MKDIR} -p ${PREFIX}/share/doc/mod_perl
		${INSTALL_DATA} ${FILESDIR}/post-install-notes ${PREFIX}/share/doc/mod_perl
		@ ${SETENV} ${MAKE_ENV} ${CONFIGURE_ENV} /usr/bin/perl ${SCRIPTDIR}/install_httpd
.if !defined(BATCH)
		@ /usr/bin/more -e ${FILESDIR}/post-install-notes
.endif

.include <bsd.port.mk>
