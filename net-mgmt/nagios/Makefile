# New ports collection makefile for:	nagios
# Date created:				19 May 2002
# Whom:					Blaz Zupan <blaz@si.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nagios
PORTVERSION=	2.0.b6
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=nagios
DISTNAME=	nagios-2.0b6

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	Extremely powerful network monitoring system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	${LOCALBASE}/libexec/nagios/check_nagios:${PORTSDIR}/net-mgmt/nagios-plugins

USE_GETOPT_LONG=yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:259
USE_RC_SUBR=	yes
USE_PERL5_BUILD=yes

PKGINSTALL=	${WRKDIR}/INSTALL
PKGDEINSTALL=	${WRKDIR}/DEINSTALL
PKGMESSAGE=	${WRKDIR}/MESSAGE

NAGIOSUSER?=	nagios
NAGIOSGROUP?=	nagios
NAGIOSDIR?=	/var/spool/nagios

NAGIOSHTMURL?=	/nagios
NAGIOSCGIURL?=	${NAGIOSHTMURL}/cgi-bin

.if defined(NAGIOSWWWDIR) || defined(WITH_NAGIOS_WWWDIR)
NAGIOSWWWDIRSET=yes
.endif

.if defined(WITH_NAGIOS_WWWDIR) && !defined(NAGIOSWWWDIR)
NAGIOSWWWDIR=	www/nagios
.else
NAGIOSWWWDIR?=	share/nagios
.endif

.include <bsd.port.pre.mk>

CPPFLAGS=	-I${LOCALBASE}/include -fPIC
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		CFLAGS="${CPPFLAGS} ${CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgd"
CONFIGURE_ARGS=	--with-command-user=${NAGIOSUSER} \
		--with-command-group=${WWWGRP} \
		--with-nagios-user=${NAGIOSUSER} \
		--with-nagios-group=${NAGIOSGROUP} \
		--with-htmurl=${NAGIOSHTMURL} \
		--with-cgiurl=${NAGIOSCGIURL} \
		--sbindir=${PREFIX}/${NAGIOSWWWDIR}/cgi-bin \
		--libexecdir=${PREFIX}/libexec/nagios \
		--datadir=${PREFIX}/${NAGIOSWWWDIR} \
		--sysconfdir=${PREFIX}/etc/nagios \
		--localstatedir=${NAGIOSDIR} \
		--prefix=${PREFIX}

PLIST_SUB=	NAGIOSDIR=${NAGIOSDIR} \
		NAGIOSWWWDIR=${NAGIOSWWWDIR} \
		NAGIOSUSER=${NAGIOSUSER} \
		NAGIOSGROUP=${NAGIOSGROUP} \
		WWWGRP=${WWWGRP}

SED_SCRIPT=	-e 's,%%NAGIOSUSER%%,${NAGIOSUSER},g' \
		-e 's,%%NAGIOSGROUP%%,${NAGIOSGROUP},g' \
		-e 's,%%NAGIOSDIR%%,${NAGIOSDIR},g' \
		-e 's,%%NAGIOSWWWDIR%%,${NAGIOSWWWDIR},g' \
		-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

INSTALL_TARGET=	all install config install-config install-commandmode

pre-everything::
.if !defined(NAGIOSWWWDIRSET)
	@${ECHO_CMD} "**********************************************************************"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " The web component of this port is currently being installed under"
	@${ECHO_CMD} " ${PREFIX}/${NAGIOSWWWDIR}, the default for which is being changed"
	@${ECHO_CMD} " when Nagios 2.0 is released.  If this is a new installation, please"
	@${ECHO_CMD} " consider adding the following option to /etc/make.conf to install the"
	@${ECHO_CMD} " component under the correct home of ${PREFIX}/www/nagios:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   # net-mgmt/nagios"
	@${ECHO_CMD} "   WITH_NAGIOS_WWWDIR=YES"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " Existing installations can be upgraded with this option with only"
	@${ECHO_CMD} " minor changes being required to etc/apache[2]/httpd.conf to change"
	@${ECHO_CMD} " references of ${PREFIX}/${NAGIOSWWWDIR} to ${PREFIX}/www/nagios."
	@${ECHO_CMD} ""
	@${ECHO_CMD} " Should you wish to continue using ${PREFIX}/${NAGIOSWWWDIR}, define"
	@${ECHO_CMD} " the NAGIOSWWWDIR variable without the ${PREFIX}/ prefix:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "   # net-mgmt/nagios"
	@${ECHO_CMD} "   NAGIOSWWWDIR=${NAGIOSWWWDIR}"
	@${ECHO_CMD} ""
	@${ECHO_CMD} " The WITH_NAGIOS_WWWDIR knob will vanish once the default has been"
	@${ECHO_CMD} " changed and the NAGIOSWWWDIR tunable option will remain permanently."
	@${ECHO_CMD} ""
	@${ECHO_CMD} "**********************************************************************"
.endif

pre-build:
	for myfile in nagios.sh INSTALL DEINSTALL MESSAGE; do \
		${SED} ${SED_SCRIPT} < ${FILESDIR}/$${myfile}.tmpl >${WRKDIR}/$${myfile}; \
	done

pre-install:
	@${SH} ${PKGINSTALL} ${DISTNAME} PRE-INSTALL

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/nagios.sh ${PREFIX}/etc/rc.d/
	@${CHMOD} 775 ${NAGIOSDIR} ${NAGIOSDIR}/archives ${NAGIOSDIR}/rw
	@${CHOWN} ${NAGIOSUSER}:${NAGIOSGROUP} ${NAGIOSDIR} ${NAGIOSDIR}/archives
	@${CHOWN} ${NAGIOSUSER}:${WWWGRP} ${NAGIOSDIR}/rw
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
