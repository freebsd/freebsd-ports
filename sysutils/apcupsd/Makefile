# New ports collection makefile for:	apcupsd
# Date created:		1.12.2001
# Whom:			Lars Köller <Lars.Koeller@Uni-Bielefeld.DE>
#
# $FreeBSD$
#

PORTNAME=	apcupsd
PORTVERSION=	3.8.5
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.apcupsd.com/pub/apcupsd/stable/tar/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

STARTUP_SCRIPT=	apcupsd.sh.sample
PLIST_SUB=	STARTUP_SCRIPT=${STARTUP_SCRIPT}

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --sbindir=${PREFIX}/sbin \
		--enable-nls --disable-install-distdir \
		--sysconfdir=${PREFIX}/etc/apcupsd \
		--with-serial-dev=/dev/usv \
		--enable-cgi --with-cgi-bin=${PREFIX}/etc/apcupsd/cgi
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		CFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

# Cause FreeBSD 3.X misses libmenu, libforms and libpanel (curses)
.if ${OSVERSION} > 400000
CONFIGURE_ARGS+=--enable-powerflute --with-libwrap
PLIST_SUB+=	POWERFL=""
.else
PLIST_SUB+=	POWERFL="@comment "
.endif

MAN8=		"apcupsd.8"

PORTDOCS=	apcupsd.pdf apcaccess.html apcnisd.html apctest.html apcupsd-styles.css \
		apcupsd.apf apcupsd.book apcupsd.gif apcupsd.html batteries.html \
		bugs.html cables.html cgiprogs.html charging.gif \
		config-examples.html configure.html data.html eprom.html \
		events.html faq.html index.html install.html invoking.html \
		kernel_config.html license.html logging.html master-slave.html \
		multiUPS.html multimon.gif new_features_3_7_0.html \
		new_features_3_8_0.html new_features_3_8_1.html \
		new_features_3_8_2.html new_features_3_8_3.html \
		new_features_3_8_4.html new_features_3_8_5.html \
		oldversions.html onbatt.gif online.gif security.html \
		shutdown.html status.gif status.html stopping.html testing.html \
		thanks.gif thanks.html troubles.html upgrading_to_3_7_0.html \
		upsbible.html usb.html win32.html wininstall1.gif wininstall2.gif \
		wininstall3.gif wininstall4.gif wininstall5.gif wininstall6.gif \
		wininstall7.gif

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} \
			  ${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/manual/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
