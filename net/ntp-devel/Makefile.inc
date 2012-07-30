# $FreeBSD: /tmp/pcvs/ports/net/ntp-devel/Makefile.inc,v 1.1 2011-11-27 23:02:28 cy Exp $

OPTIONS=	NTPSNMPD	"Build and install ntpsnmpd" OFF \
		SSL		"Enable SSL" ON \
		IPV6		"Enable IPv6" OFF \
  		BANCOMM		"Enable Datum/Bancomm bc635/VME interface" OFF \
  		GPSVME		"Enable TrueTime GPS receiver/VME interface" OFF \
  		ACTS		"Enable ACTS modem service" OFF \
  		ARBITER		"Enable Arbiter 1088A/B GPS receiver" OFF \
  		ARCRON_MSF	"Enable Arcron MSF receiver" OFF \
  		AS2201		"Enable Austron 2200A/2201A GPS receiver" OFF \
  		ATOM		"Enable ATOM PPS interface" ON \
  		CHRONOLOG	"Enable Chrono-log K-series WWVB receiver" OFF \
  		CHU		"Enable CHU modem/decoder" OFF \
  		AUDIO_CHU	"Enable CHU audio/decoder" OFF \
  		DATUM		"Enable Datum Programmable Time System" OFF \
  		DUMBCLOCK	"Enable Dumb generic hh:mm:ss local clock" OFF \
  		FG		"Enable Forum Graphic GPS" OFF \
  		HEATH		"Enable Heath GC-1000 WWV/WWVH receiver" OFF \
  		HOPFSERIAL	"Enable hopf serial clock device" OFF \
  		HOPFPCI		"Enable hopf 6039 PCI board" OFF \
  		HPGPS		"Enable HP 58503A GPS receiver" OFF \
  		IRIG		"Enable IRIG audio decoder" OFF \
  		JJY		"Enable JJY receiver" OFF \
  		JUPITER		"Enable Rockwell Jupiter GPS receiver" OFF \
  		LEITCH		"Enable Leitch CSD 5300 Master Clock" OFF \
  		LOCAL_CLOCK	"Enable local clock reference" OFF \
  		MX4200		"Enable Magnavox MX4200 GPS receiver" OFF \
  		NEOCLOCK4X	"Enable NeoClock4X DCF77 / TDF receiver" OFF \
  		NMEA		"Enable NMEA GPS receiver" ON \
  		ONCORE		"Enable Motorola VP/UT Oncore GPS receiver" OFF \
  		PALISADE	"Enable Palisade clock" OFF \
  		PCF		"Enable Conrad parallel port radio clock" OFF \
  		PST		"Enable PST/Traconex 1020 WWV/WWVH receiver" OFF \
  		RIPENCC		"Enable RIPENCC specific Trimble driver" OFF \
  		SHM		"Enable SHM clock attached thru shared memory" OFF \
  		SPECTRACOM	"Enable Spectracom 8170/Netclock/2 WWVB" OFF \
  		TRUETIME	"Enable Kinemetrics/TrueTime receivers" OFF \
  		ULINK		"Enable Ultralink WWVB receiver" OFF \
  		WWV		"Enable WWV Audio receiver" OFF \
  		ZYFER		"Enable Zyfer GPStarplus receiver" OFF \
  		COMPUTIME	"Enable Diem Computime Radio Clock" OFF \
  		DCF7000		"Enable ELV/DCF7000 clock" OFF \
  		HOPF6021	"Enable HOPF 6021 clock" OFF \
  		MEINBERG	"Enable Meinberg clocks" OFF \
  		RAWDCF		"Enable DCF77 raw time code" OFF \
  		RCC8000		"Enable RCC 8000 clock" OFF \
  		SCHMID		"Enable Schmid DCF77 clock" OFF \
  		TRIMTAIP	"Enable Trimble GPS receiver/TAIP protocol" OFF \
  		TRIMTSIP	"Enable Trimble GPS receiver/TSIP protocol" OFF \
  		WHARTON		"Enable WHARTON 400A Series clock" OFF \
  		VARITEXT	"Enable VARITEXT clock" OFF

# Not supported by FreeBSD:   		TPRO		"Enable KSI/Odetics TPRO/S GPS receiver/IRIG" OFF \
# XXX Broken under FreeBSD: TT560		"Enable TrueTime 560 IRIG-B decoder" OFF \

NTP_DRIVERS= \
  		BANCOMM \
  		GPSVME \
  		ACTS \
  		ARBITER \
  		ARCRON_MSF \
  		AS2201 \
  		ATOM \
  		CHRONOLOG \
  		CHU \
  		AUDIO_CHU \
  		DATUM \
  		DUMBCLOCK \
  		FG \
  		HEATH \
  		HOPFSERIAL \
  		HOPFPCI \
  		HPGPS \
  		IRIG \
  		JJY \
  		JUPITER \
  		LEITCH \
  		LOCAL_CLOCK \
  		MX4200 \
  		NEOCLOCK4X \
  		NMEA \
  		ONCORE \
  		PALISADE \
  		PCF \
  		PST \
  		RIPENCC \
  		SHM \
  		SPECTRACOM \
  		TRUETIME \
  		ULINK \
  		WWV \
  		ZYFER \
  		COMPUTIME \
  		DCF7000 \
  		HOPF6021 \
  		MEINBERG \
  		RAWDCF \
  		RCC8000 \
  		SCHMID \
  		TRIMTAIP \
  		TRIMTSIP \
  		WHARTON \
  		VARITEXT
