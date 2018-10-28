--- src/calculator/gasCalculator.cpp.orig	2018-10-24 05:36:48 UTC
+++ src/calculator/gasCalculator.cpp
@@ -139,7 +139,7 @@ void gasCalculator::calculatePressure()
     double temp = m_temp.convertTo( KUnitConversion::Kelvin ).number();
     double b = m_Vand_b.convertTo( KUnitConversion::Liter ).number();
 
-    double pressure = m_moles * R * temp / (volume - m_moles * b) - m_moles * m_moles * m_Vand_a / volume / volume;
+    double pressure = m_moles * Rgas * temp / (volume - m_moles * b) - m_moles * m_moles * m_Vand_a / volume / volume;
 
     m_pressure = Value(pressure, KUnitConversion::Atmosphere );
     m_pressure = m_pressure.convertTo(getCurrentUnitId(ui.pressure_unit));
@@ -154,7 +154,7 @@ void gasCalculator::calculateMolarMass()
     double temp = m_temp.convertTo(KUnitConversion::Kelvin).number();
     double b = m_Vand_b.convertTo(KUnitConversion::Liter).number();
 
-    m_molarMass = mass * R * temp / (pressure + m_moles * m_moles * m_Vand_a / volume / volume)\
+    m_molarMass = mass * Rgas * temp / (pressure + m_moles * m_moles * m_Vand_a / volume / volume)\
                   / (volume - m_moles * b);
     ui.molarMass->setValue(m_molarMass);
 }
@@ -165,7 +165,7 @@ void gasCalculator::calculateVol()
     double temp = m_temp.convertTo(KUnitConversion::Kelvin).number();
     double b = m_Vand_b.convertTo(KUnitConversion::Liter).number();
 
-    double volume = m_moles * R * temp / pressure + (m_moles * b);
+    double volume = m_moles * Rgas * temp / pressure + (m_moles * b);
     m_vol = Value(volume, KUnitConversion::Liter);
     m_vol = m_vol.convertTo( getCurrentUnitId(ui.volume_unit) );
     ui.volume->setValue(m_vol.number());
@@ -178,7 +178,7 @@ void gasCalculator::calculateTemp()
     double b = m_Vand_b.convertTo(KUnitConversion::Liter).number();
 
     double temp = (pressure + (m_moles * m_moles * m_Vand_a / volume / volume))\
-                  * (volume - m_moles * b) / m_moles / R;
+                  * (volume - m_moles * b) / m_moles / Rgas;
     m_temp = Value(temp, KUnitConversion::Kelvin);
     m_temp = m_temp.convertTo( getCurrentUnitId( ui.temp_unit ) );
     ui.temp->setValue(m_temp.number());
@@ -192,7 +192,7 @@ void gasCalculator::calculateMoles()
     double b = m_Vand_b.convertTo(KUnitConversion::Liter).number();
 
     m_moles = (pressure + m_moles * m_moles * m_Vand_a / volume / volume)\
-              * (volume - m_moles * b) / R / temp;
+              * (volume - m_moles * b) / Rgas / temp;
     ui.moles->setValue(m_moles);
 }
 
@@ -204,7 +204,7 @@ void gasCalculator::calculateMass()
     double b = m_Vand_b.convertTo(KUnitConversion::Liter).number();
 
     double mass = (pressure + m_moles * m_moles * m_Vand_a / volume / volume)\
-                  * (volume - m_moles * b) * m_molarMass / R / temp;
+                  * (volume - m_moles * b) * m_molarMass / Rgas / temp;
     m_mass = Value(mass, KUnitConversion::Gram);
     m_mass = m_mass.convertTo( getCurrentUnitId( ui.mass_unit ) );
     ui.mass->setValue(m_mass.number());
