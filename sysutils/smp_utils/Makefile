# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smp_utils
PORTVERSION=	0.97
CATEGORIES=	sysutils
MASTER_SITES=	http://sg.danny.cz/sg/p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Utilities to send SAS Serial Management Protocol requests

USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

MAN8=		smp_conf_general.8
MAN8+=		smp_conf_phy_event.8
MAN8+=		smp_conf_route_info.8
MAN8+=		smp_conf_zone_man_pass.8
MAN8+=		smp_conf_zone_perm_tbl.8
MAN8+=		smp_conf_zone_phy_info.8
MAN8+=		smp_discover.8
MAN8+=		smp_discover_list.8
MAN8+=		smp_ena_dis_zoning.8
MAN8+=		smp_phy_control.8
MAN8+=		smp_phy_test.8
MAN8+=		smp_read_gpio.8
MAN8+=		smp_rep_broadcast.8
MAN8+=		smp_rep_exp_route_tbl.8
MAN8+=		smp_rep_general.8
MAN8+=		smp_rep_manufacturer.8
MAN8+=		smp_rep_phy_err_log.8
MAN8+=		smp_rep_phy_event.8
MAN8+=		smp_rep_phy_event_list.8
MAN8+=		smp_rep_phy_sata.8
MAN8+=		smp_rep_route_info.8
MAN8+=		smp_rep_self_conf_stat.8
MAN8+=		smp_rep_zone_man_pass.8
MAN8+=		smp_rep_zone_perm_tbl.8
MAN8+=		smp_utils.8
MAN8+=		smp_write_gpio.8
MAN8+=		smp_zone_activate.8
MAN8+=		smp_zoned_broadcast.8
MAN8+=		smp_zone_lock.8
MAN8+=		smp_zone_unlock.8

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900000
IGNORE=		requires FreeBSD 9.x
.endif

.include <bsd.port.post.mk>
