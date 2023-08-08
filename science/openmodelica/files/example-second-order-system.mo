model SecondOrderSystem "A second order rotational system"
  type Angle=Real(unit="rad");
  type AngularVelocity=Real(unit="rad/s");
  type Inertia=Real(unit="kg.m2");
  type Stiffness=Real(unit="N.m/rad");
  type Damping=Real(unit="N.m.s/rad");
  parameter Inertia J1=0.4 "Moment of inertia for inertia 1";
  parameter Inertia J2=1.0 "Moment of inertia for inertia 2";
  parameter Stiffness c1=11 "Spring constant for spring 1";
  parameter Stiffness c2=5 "Spring constant for spring 2";
  parameter Damping d1=0.2 "Damping for damper 1";
  parameter Damping d2=1.0 "Damping for damper 2";
  Angle phi1 "Angle for inertia 1";
  Angle phi2 "Angle for inertia 2";
  AngularVelocity omega1 "Velocity of inertia 1";
  AngularVelocity omega2 "Velocity of inertia 2";
initial equation
  phi1 = 0;
  phi2 = 1;
  omega1 = 0;
  omega2 = 0;
equation
  // Equations for inertia 1
  omega1 = der(phi1);
  J1*der(omega1) = c1*(phi2-phi1)+d1*der(phi2-phi1);
  // Equations for inertia 2
  omega2 = der(phi2);
  J2*der(omega2) = c1*(phi1-phi2)+d1*der(phi1-phi2)-c2*phi2-d2*der(phi2);
end SecondOrderSystem;

