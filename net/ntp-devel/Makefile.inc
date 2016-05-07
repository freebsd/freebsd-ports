# $FreeBSD$

OPTIONS_DEFINE=	NTPSNMPD \
		SSL \
		IPV6 \
		NTP_SIGND \
		BANCOMM	 \
		GPSVME \
		ACTS \
		ARBITER	 \
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
		HOPFPCI	 \
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
		PERL_UTILS \
		PST \
		RIPENCC \
		SHM \
		SPECTRACOM \
		TRUETIME \
		ULINK \
		WWV \
		ZYFER \
		COMPUTIME \
		DCF7000	 \
		HOPF6021 \
		MEINBERG \
		RAWDCF	 \
		RCC8000 \
		SCHMID \
		SEL240X \
		TRIMTAIP \
		TRIMTSIP \
		WHARTON	 \
		VARITEXT \
		DOCS \
		EXAMPLES

OPTIONS_DEFAULT=	SSL \
		ATOM \
		PERL_UTILS \
		NMEA

NTPSNMPD_DESC=	Build and install ntpsnmpd
NTP_SIGND_DESC=	Enable signed NTP
BANCOMM_DESC=	Enable Datum/Bancomm bc635/VME interface
GPSVME_DESC=	Enable TrueTime GPS receiver/VME interface
ACTS_DESC=	Enable ACTS modem service
ARBITER_DESC=	Enable Arbiter 1088A/B GPS receiver
ARCRON_MSF_DESC=	Enable Arcron MSF receiver
AS2201_DESC=	Enable Austron 2200A/2201A GPS receiver
ATOM_DESC=	Enable ATOM PPS interface
CHRONOLOG_DESC=	Enable Chrono-log K-series WWVB receiver
CHU_DESC=	Enable CHU modem/decoder
AUDIO_CHU_DESC=	Enable CHU audio/decoder
DATUM_DESC=	Enable Datum Programmable Time System
DUMBCLOCK_DESC=	Enable Dumb generic hh:mm:ss local clock
FG_DESC=	Enable Forum Graphic GPS
HEATH_DESC=	Enable Heath GC-1000 WWV/WWVH receiver
HOPFSERIAL_DESC=	Enable hopf serial clock device
HOPFPCI_DESC=	Enable hopf 6039 PCI board
HPGPS_DESC=	Enable HP 58503A GPS receiver
IRIG_DESC=	Enable IRIG audio decoder
JJY_DESC=	Enable JJY receiver
JUPITER_DESC=	Enable Rockwell Jupiter GPS receiver
LEITCH_DESC=	Enable Leitch CSD 5300 Master Clock
LOCAL_CLOCK_DESC=	Enable local clock reference
MX4200_DESC=	Enable Magnavox MX4200 GPS receiver
NEOCLOCK4X_DESC=	Enable NeoClock4X DCF77 / TDF receiver
NMEA_DESC=	Enable NMEA GPS receiver
ONCORE_DESC=	Enable Motorola VP/UT Oncore GPS receiver
PALISADE_DESC=	Enable Palisade clock
PCF_DESC=	Enable Conrad parallel port radio clock
PERL_UTILS_DESC=	Install ntp-wait and ntptrace utilities
PST_DESC=	Enable PST/Traconex 1020 WWV/WWVH receiver
RIPENCC_DESC=	Enable RIPENCC specific Trimble driver
SHM_DESC=	Enable SHM clock attached thru shared memory
SPECTRACOM_DESC=	Enable Spectracom 8170/Netclock/2 WWVB
TRUETIME_DESC=	Enable Kinemetrics/TrueTime receivers
ULINK_DESC=	Enable Ultralink WWVB receiver
WWV_DESC=	Enable WWV Audio receiver
ZYFER_DESC=	Enable Zyfer GPStarplus receiver
COMPUTIME_DESC=	Enable Diem Computime Radio Clock
DCF7000_DESC=	Enable ELV/DCF7000 clock
HOPF6021_DESC=	Enable HOPF 6021 clock
MEINBERG_DESC=	Enable Meinberg clocks
RAWDCF_DESC=	Enable DCF77 raw time code
RCC8000_DESC=	Enable RCC 8000 clock
SCHMID_DESC=	Enable Schmid DCF77 clock
SEL240X_DESC=	Enable SEL 240X clocks
TRIMTAIP_DESC=	Enable Trimble GPS receiver/TAIP protocol
TRIMTSIP_DESC=	Enable Trimble GPS receiver/TSIP protocol
WHARTON_DESC=	Enable WHARTON 400A Series clock
VARITEXT_DESC=	Enable VARITEXT clock

# Not supported by FreeBSD:   	TPRO	Enable KSI/Odetics TPRO/S GPS receiver/IRIG
# XXX Broken under FreeBSD: TT560	Enable TrueTime 560 IRIG-B decoder

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
		SEL240X \
		TRIMTAIP \
		TRIMTSIP \
		WHARTON \
		VARITEXT
